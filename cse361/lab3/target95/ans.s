 mov  %rsp, %rax
 mov  %rax, %rdi 
 pop  %rax 
 movl %eax, %ecx
 movl %ecx, %edx
 movl %edx, %esi
 lea  (%rdi, %rsi, 1), %rax 
 mov  %rax, %rdi
