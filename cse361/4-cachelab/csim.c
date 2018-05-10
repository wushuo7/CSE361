#include "cachelab.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
//#include <sstream>
//#include <fstream>
// name: Shuo Wu
// WUSTL key: wushuo
// Student ID: 452666
/*
int main()
{
    printSummary(0, 0, 0);
    return 0;
}
*/


typedef struct cache_property{
    int S;// the number of set 
    int s;
    int B;// byte/block
    int b;
    int E;
    int hit;
    int miss;
    int evict;
    //int verbose;
}cache_property;
//struct
typedef struct{
    int valid;
    long long tag; // maybe 22bits
    int index_right_now; // to teel which line to move out
    char * block;
    
}cache_line;
typedef struct{
    cache_line * line;
}cache_set;
typedef struct{
    cache_set * set;
}cache;
// initial a new chache 
cache create_cache(long long S, int E) 
{
    cache answer;    
    cache_set set;
    cache_line line;
    line.index_right_now = 0;
    line.valid = 0; 
    line.tag = 0; 
    answer.set = (cache_set *) malloc(sizeof(cache_set) * S);
    //build the set
    //set.line =  (cache_line *) malloc(sizeof(cache_line) * E);
    
    
        //loop to construct the lines
    for(int i = 0; i < S; i++){
        set.line =  (cache_line *) malloc(sizeof(cache_line) * E);
        for(int i =0;i<E;i++){
            set.line[i] = line;
        }
        answer.set[i] = set;
    }
    
    return answer;
}

// check hit or not 
bool hit(cache_line line, unsigned long long tag){
    if(line.valid ==1 ){
        if(line.tag == tag){
            return true;
        }
    }
    return false;
    
}
//check full ->miss
bool checkFull(cache_set set, cache_property this){
    
    for(int i = 0; i<this.E; i++){
        if(set.line[i].valid == 0){
            return false;
        }
    }
    return true;
}
// if full, find next, return line number 
int find_next(cache_set set, cache_property this_one){
    for(size_t i=0; i<this_one.E;i++){
        if(set.line[i].valid == 0){
            int answer = (int)i;
            return answer;
        }

    }
    return -10;
}


//find min and find max
// if min, move out
int get_min(cache_set set, cache_property this){
    int first_index = set.line[0].index_right_now;
    int ava =0;
    for (int i =0; i < this.E; i++){
        if(first_index > set.line[i].index_right_now){
            ava = i;
            first_index = set.line[i].index_right_now;
        }
    }
    return ava;
}
// update the largest one
int get_max(cache_set set, cache_property this){
    int first_index = set.line[0].index_right_now;
    int ava =0;
    for (int i =0; i < this.E; i++){
        if(first_index < set.line[i].index_right_now){
            ava = i;
            first_index = set.line[i].index_right_now;
        }
    }
    return ava;

}

// most important part, bulid simulator 
cache_property mock(cache current, cache_property this, unsigned long long address){
    int tag_size = 64- this.s -this.b;
    // bulid the mock address 
    unsigned long long tag = address >>(this.s +this.b);
    // get set index
    unsigned long long set_index = (address <<(tag_size))>>(tag_size+ this.b);
    cache_set set1= current.set[set_index];

    int hit_amout =0;
    for(int i =0; i<this.E; i++){
        cache_line line_right_now = set1.line[i];
        if(hit(line_right_now, tag) == true){
            this.hit = this.hit +1;
            int newest = get_max(set1,this);
            hit_amout =1;
            // uodate the time to use this line
            current.set[set_index].line[i].index_right_now = current.set[set_index].line[newest].index_right_now+1;
            
        }
    }
    if(hit_amout ==0 && checkFull(set1, this)==false){
        this.miss ++;
        int index =find_next(set1, this);
        set1.line[index].tag = tag;
        set1.line[index].valid =1;
        int newest = get_max(set1,this);
        current.set[set_index].line[index].index_right_now = current.set[set_index].line[newest].index_right_now+1;
    }
    
    else if(hit_amout ==0){ // no more room in this set
        this.miss++;
        this.evict++;
        int line_to_change = get_min(set1, this);  
        // change the tag of t
        set1.line[line_to_change].tag =tag;
        int newest = get_max(set1,this);
        current.set[set_index].line[line_to_change].index_right_now = current.set[set_index].line[newest].index_right_now+1;
    

    }
    return this;

}
void print_usage_information(){
    printf("Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file>\n");
    printf("Options:\n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -s <num>   Number of set index bits.\n");
    printf("  -E <num>   Number of lines per set.\n");
    printf("  -b <num>   Number of block offset bits.\n");
    printf("  -t <file>  Trace file.\n");
    printf("\n");
    printf("Examples:\n");
    printf("  linux>  ./csim -s 4 -E 1 -b 4 -t traces/yi.trace\n");
    printf("  linux>  ./csim -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
}

int main(int argc, char* argv[])
{
    bool IsVisiable =false;
    cache answer;
    cache_property this;
    FILE* file_name;
    char set_value;
    
    char * input_string = "s:E:b:t:vh";
    while( (set_value=getopt(argc,argv, input_string)) != -1)
    {
        switch(set_value){
        case 's':
            this.s = atoi(optarg);
            break;
        case 'E':
            this.E = atoi(optarg);
            break;
        case 'b':
            this.b = atoi(optarg);
            break;
        case 't':
            file_name = fopen(optarg,"r");
            break;
        case 'v':
            IsVisiable = true;
            break;
        //help
        case 'h':
            print_usage_information();
            exit(0);
        default:
            print_usage_information();
            exit(-10);
        }
    }
    //compute S and B
    //int check1 =1;
    this.S = 1<<this.s;
    this.B = 1<<this.b;
    //creat a new cache based on the input
    answer = create_cache(this.S, this.E);
    //initialize the counters
    this.miss = 0;
    this.hit = 0;
    this.evict = 0;
    char ident;
    unsigned addr;
    int size;
    int a = this.miss;
    int b = this.hit;
    int c = this.evict;
    //wrap the trace into tmp
    
    while(fscanf(file_name," %c %x,%d",&ident, &addr, &size) > 0){
        
        //fscanf(tmp, " %c %llx,%d", command, address, size) == 3
        switch(ident){
            case 'I':
                break;
            case 'L':
                this = mock(answer, this, addr);
                if (IsVisiable){
                    printf("%c %x,%d",ident, addr, size);
                    if(a!= this.miss){
                        printf("%s"," miss");
                        a = this.miss;
                    }
                    if(b!= this.hit){
                        printf("%s"," hit");
                        b = this.hit;
                    }
                    if(c!= this.evict){
                        printf("%s"," evict");
                        a = this.evict;
                    }
                    printf("\n");
                }
                break;
            case 'S':
                this = mock(answer, this, addr);
                if (IsVisiable){
                    printf("%c %x,%d",ident, addr, size);
                    if(a!= this.miss){
                        printf("%s"," miss");
                        a = this.miss;
                    }
                    if(b!= this.hit){
                        printf("%s"," hit");
                        b = this.hit;
                    }
                    if(c!= this.evict){
                        printf("%s"," evict");
                        a = this.evict;
                    }
                    printf("\n");
                }
                break;
            //twice for M
            case 'M':
                this = mock(answer, this, addr); // miss
                this = mock(answer, this, addr); // hit
                if (IsVisiable){
                    printf("%c %x,%d",ident, addr, size);
                    if(a!= this.miss){
                        printf("%s"," miss");
                        a = this.miss;
                    }
                    if(b!= this.hit){
                        printf("%s"," hit");
                        b = this.hit;
                    }
                    if(c!= this.evict){
                        printf("%s"," evict");
                        a = this.evict;
                    }
                    printf("\n");
                }
                break;
            default:
                break;
        }
    }
    //print result
    printf("%d\n",this.hit);
    printSummary(this.hit, this.miss, this.evict);
    fclose(file_name);
    return 0;
}


