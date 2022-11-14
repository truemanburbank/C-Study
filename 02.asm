%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    PRINT_STRING msg
    
    xor rax, rax
    ret
    
    ; 초기화된 테이터
    ; [변수 이름] [크기] [초기값]
    ; [크기byte] db(1) dw(2) dd(4) dq(8)
section .data
    ; 일련의 데이터가 각각 1byte 아스키 코드 값으로 저장됨
    ; "Hello World" 대신 아스키 코드 값을 각각 일렬로 넣어도 같은 결
    msg db "Hello World", 0x00  ; 0은 문자가 끝남(NULL)을 의미
    
    a db 0x11   ; [0x11] -> 데이터의 본질(0001 0001)을 
                ; 16진수 형식으로 읽은 것
                ; 이 데이터를 10진수로 읽으면 17
                ; 데이터는 같은데 읽는 방식에 따라 다르다.
    
    b dd 0x12345678 ; 숫자가 메모리에 뒤집어서 저장됨(리틀 엔디안)
    ; - 리틀 엔디언 : 캐스팅에 유리하다
    ; - 빅 엔디언 : 숫자 비교에 유리하다
                
    ; a db 0x11, 0x11, 0x11, 0x11 일련의 데이터 선언 가능 
    
    ; 초기화되지 않은 데이터
    ; [변수 이름] [크기] [개수]
    ; [크기byte] resb(1) resw(2) resd(4) resq(8)
section .bss
    e resb 10
   