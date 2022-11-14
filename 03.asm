%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    ; 입력을 받음 
    GET_DEC 1, al
    GET_DEC 1, num
    
    ;PRINT_DEC 1, al
    ;NEWLINE
    ;PRINT_DEC 1, num
    
    ; 더하기 연산
    ; add a, b (a = a + b)
    ; a는 레지스터 or 메모리
    ; b는 레지스터 or 메모리 or 상수
    ; 단 a, b 모두 메모리는 x
    
    ; 빼기 연산
    ; sub a,b (a = a - b)
    
    add al, 1 ; 레지스터 + 상수
    PRINT_DEC 1, al ; 1 + 1 = 2
    NEWLINE
    
    ; add al, num  num의 주소값이 들어감 -> crash
    add al, [num] ; num의 값이 들어감, 레지스터 + 메모리 
    PRINT_DEC 1, al ; 2 + 2 =4
    NEWLINE
    
    mov bl, 3 ; 레지스터 + 레지스터 
    add al, bl
    PRINT_DEC 1, al ; 4 + 3 = 7
    NEWLINE
    
    ; 메모리에 상수를 더할 때는 바이트 크기도 지정해 줘야 함 
    add [num], byte 1 ; 메모리 + 상수
    PRINT_DEC 1, [num] ; 2 + 1
    NEWLINE
    
    add [num], al ; 메모리 + 레지스터 
    PRINT_DEC 1, [num] ; 3 + 7
    NEWLINE   
    
    ; 곱하기 연산
    ; mul reg
    ; - mul bl => al * bl
    ; -- 연산 결과를 ax에 저장 
    ; - mul bx => ax * bx
    ; -- 연산 결과를 dx(상위 16비트) ax(하위 16비트)에 저장
    ; - mul ebx => eax * ebx
    
    ; ex) 5 * 8 은?
    mov ax, 0
    mov al, 5
    mov bl, 8
    mul bl
    PRINT_DEC 2, ax
    NEWLINE  
    
    ; 나누기 연산
    ; div reg
    ; - div bl => ax / bl
    ; -- 연산 결과는 al(몫), ah(나머지)
    
    ; ex) 100 / 3은?
    mov ax, 100
    mov bl, 3
    div bl
    PRINT_DEC 1, al
    NEWLINE
    mov al, ah
    PRINT_DEC 1, al
            
                                        
    xor rax, rax
    ret
    
    ; 초기화된 테이터
    ; [변수 이름] [크기] [초기값]
    ; [크기byte] db(1) dw(2) dd(4) dq(8)
;section .data
   
                
    ; a db 0x11, 0x11, 0x11, 0x11 일련의 데이터 선언 가능 
    
    ; 초기화되지 않은 데이터
    ; [변수 이름] [크기] [개수]
    ; [크기byte] resb(1) resw(2) resd(4) resq(8)
section .bss
    num resb 1
   