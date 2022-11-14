%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    ; 쉬프트(shift) 연산, 논리(logical) 연산
    
    mov eax, 0x12345678 ; 숫자 2개가 1byte ㅎㅎ...
    PRINT_HEX 4, eax
    NEWLINE
    shl eax, 8 ; 8 비트를 왼쪽으로 시프트한다는 것은 최상위 8 비트 분실
    PRINT_HEX 4, eax
    NEWLINE
    shr eax, 8 ; 다시 오른쪽으로 8비트 시프트 (상위 비트 0으로 채움)
    PRINT_HEX 4, eax
    NEWLINE
    
    ; shl -> 2배 커짐
    ; shr -> 2배 작아짐
    ; 곱셈, 나눗셈 빠르게 할 수 있음
    ; 게임 서버에서 ObjectID를 만들어 줄 때 
    
    ; not and or xor
    ; xor : 서로 다를 때만 1, 같을 때는 0
    
    mov al, 0b10010101
    mov bl, 0b01111100
    
    ; 0b00010100 => 0x14
    and al, bl ; al = al and bl
    PRINT_HEX 1, al
    NEWLINE
    
    ; 0b11101011 => 0xeb
    not al
    PRINT_HEX 1, al
    NEWLINE
                        
    ; 응용 사례 : bitflag
    
    ; 동일한 값을 xor 두 번하면 자기 자신으로 되돌아오는 특성
    ; 암호학에서 유용하다. (value xor key)
    
    mov al, 0b10010101
    mov bl, 0b01111100
    
    NEWLINE
    PRINT_HEX 1, al
    NEWLINE
    xor al, bl
    PRINT_HEX 1, al
    NEWLINE
    xor al, bl
    PRINT_HEX 1, al
    NEWLINE
               
    ; 자기 자신을 xor하면 0이 된다.
    xor al, al
    PRINT_HEX 1, al
    
    ; return 0 와 비슷                                                                                                                                                                                                                                                                                                                                                                                                                                       
    xor rax, rax ; == mov rax, 0
    ret
    
    ; 초기화된 테이터
    ; [변수 이름] [크기] [초기값]
    ; [크기byte] db(1) dw(2) dd(4) dq(8)
section .data     

                  
    ; 초기화되지 않은 데이터
    ; [변수 이름] [크기] [개수]
    ; [크기byte] resb(1) resw(2) resd(4) resq(8)
section .bss
    num resb 1
   