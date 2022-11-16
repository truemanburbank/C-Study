%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    ; 배열과 주소 
    
    ; 배열 : 동일한 타입의 데이터 묶음 
    ; - 배열을 구성하는 각 값을 배열 요소(element)라고 함
    ; - 배열의 위치를 가리키는 숫자를 인덱스(index)라고 함
    
    ; 주소
    ; [시작 주소 + 인덱스 * 크]
    
    ;PRINT_HEX 1, [a] ; a의 첫번째 값 
    ;NEWLINE
    
    ;PRINT_HEX 1, [a+1] ; a의 첫번째 값 
    ;NEWLINE
    
    ;PRINT_HEX 1, [a+2] ; a의 첫번째 값 
    ;NEWLINE
    
    ; 연습 문제 : a 배열의 모든 데이터 출력해 보기
    ;xor ecx, ecx
  
;LABEL_PRINT_A:
    ;PRINT_HEX 1, [a + ecx]
    ;NEWLINE
    ;inc ecx
    ;cmp ecx, 5
    ;jne LABEL_PRINT_A
    
    
    xor ecx, ecx
LABEL_PRINT_B:
    ; 데이터가 2바이트라서 주소를 한 칸씩만 이동하면 안 되고 2칸씩 이동해야 함 
    PRINT_HEX 2, [b+ecx*2]
    NEWLINE
    inc ecx 
    cmp ecx, 5
    jne LABEL_PRINT_B
                                        
    xor rax, rax
    ret
    
    ; 초기화된 테이터
    ; [변수 이름] [크기] [초기값]
    ; [크기byte] db(1) dw(2) dd(4) dq(8)
;section .data
    a db 0x01, 0x02, 0x03, 0x04, 0x05 ; 5 * 1 = 5 바이트짜리 데이터 
    
    ; 0x01, 0x00 - 엔디안 => 0x0001 
    b times 5 dw 1 ; 2바이트 배열 5개, 초기값은 1, 10 바이트 데이터 기
    
    
                
    ; a db 0x11, 0x11, 0x11, 0x11 일련의 데이터 선언 가능 
    
    ; 초기화되지 않은 데이터
    ; [변수 이름] [크기] [개수]
    ; [크기byte] resb(1) resw(2) resd(4) resq(8)
section .bss
    num resb 10 ; 바이트가 10개짜리 있다. 
   