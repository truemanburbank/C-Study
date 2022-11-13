%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    mov eax, 0x1234
    mov rbx, 0x12345678
    mov cl, 0xff
    
    mov al, 0x00
   
    ; 메모리 <-> 레지스터
    mov rax, a ; a의 주소를 rax에 복사
    mov rax, [a] ; a의 값(범위를 넘어)을 rax에 복사섬
    mov al, [a]
    
    mov [a], byte 0x55 ; 상수를 변수에 넣을 땐 크기를 지정
    mov [a], word 0x6666
    mov [a], cl
    
    
    xor rax, rax
    ret
    
    ; 변수의 선언 및 사용
    
    ; 메모리에는 구분할 수 있도록 주소가 있다
    
    ; 초기화된 테이터
    ; [변수 이름] [크기] [초기값]
    ; [크기byte] db(1) dw(2) dd(4) dq(8)
section .data
    a db 0x11   ; [0x11]
    b dw 0x2222
    c dd 0x33333333
    d dq 0x4444444444444444
    
    ; 초기화되지 않은 데이터
    ; [변수 이름] [크기] [개수]
    ; [크기byte] resb(1) resw(2) resd(4) resq(8)
section .bss
    e resb 10
   