%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ; Base Pointer와 Stack Pointer
    mov rbp, rsp; for correct debugging
    ; 스택 메모리, 스택 프레임
   
   ; 레지스터는 다양한 용도로 사용
   ; - a b c d 범용 레지스터
   ; 포인터 레지스터 (포인터 = 위치를 가리키는~)
   ; -- ip (Instruction Pointer) : 다음 수행 명령어의 위치
   ; -- sp (Stack Pointer) : 현재 스택 top 위치 (일종이 cursur)
   ; -- bp (Base Pointer) : 스택 상대주소 계산용
   
   push rax ; 원래 있던 rax 값 저장
   push rbx ; 원래 있던 rbx 값 저장 
   
   push 1
   push 2
   call MAX
   PRINT_DEC 8, rax
   NEWLINE
   
   add rsp, 16
   pop rbx ; 다시 복원 
   pop rax ; 다시 복원 
                    
    xor rax, rax
    ret
MAX:
    push rbp ; 상대주소 계산하는 데 사용 
    mov rbp, rsp
    
    mov rax, [rbp+16]
    mov rbx, [rbp+24]
    cmp rax, rbx
    jg L1
    mov rax, rbx
L1: 
    pop rbp
    ret   
 
    ; [!] 스택이라는 메모리 영역 사용
    ; 함수가 사용하는 일종의 메모장
    ; - 매개 변수 전달
    ; - 돌아갈 주소 관리 
    
    ; 초기화된 테이터
    ; [변수 이름] [크기] [초기값]
    ; [크기byte] db(1) dw(2) dd(4) dq(8)
section .data
    msg db 'Hello, World', 0x00
    
    ; 초기화되지 않은 데이터
    ; [변수 이름] [크기] [개수]
    ; [크기byte] resb(1) resw(2) resd(4) resq(8)
section .bss
    num resb 10 ; 바이트가 10개짜리 있다. 