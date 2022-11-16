%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    ; 함수 (프로시저, 서브 루틴)
    
    ;call PRINT_MSG
    mov eax, 10
    mov ebx, 15
    call MAX
    PRINT_DEC 4, ecx
    NEWLINE
                    
    xor rax, rax
    ret
    
PRINT_MSG:
    PRINT_STRING msg
    NEWLINE   
    ret ; 종료 
    
; EX) 두 값중 더 큰 값을 반환하는 MAX 함수 
; 근데 두 값을 어떻게 남겨 받지? 반환 어떻게?
; eax와 ebx 입력값을 ecx에 반환
MAX:
    cmp eax, ebx
    jg L1
    mov ecx, ebx
    jmp L2
L1: 
    mov ecx, eax
L2:
    ret
    ; 그런데 인자가 10개라면 어떻게 할까?
    ; eax, ebx에 이미 중요한 값이 있으면 어떻게 할까?
    ; [!] .data .bss 사용하면? 
    ; 인자를 도대체 몇 개를 할당해야 하지?
    
    ; 다른 메모리 구조가 필요하다.
    ; - 어떤 꿈이 유효한 동안에는 그 꿈을 유지시켜야 함 (유효 범위의 개념이 있다.)
    ; - 어떤 꿈이 끝나면 그 꿈을 부셔버려도 됨 (정리의 개념이 있다.)
    ; - 꿈에서도 또 꿈을 꿀 수 있다는 것을 고려해야 한다. (유동적으로 유효 범위 확장 가)
    
    ; [!] 스택이라는 메모리 영역 사용
    ; 함수가 사용하는 일종의 메모장
    ; - 매개 변수 전달
    ; - 돌아갈 주소 관리 
    
    
    ; 초기화된 테이터
    ; [변수 이름] [크기] [초기값]
    ; [크기byte] db(1) dw(2) dd(4) dq(8)
section .data
    msg db 'Hello, World', 0x00
    dd a 0
    dd b 0
    dd c 0
    
    ; 초기화되지 않은 데이터
    ; [변수 이름] [크기] [개수]
    ; [크기byte] resb(1) resw(2) resd(4) resq(8)
section .bss
    num resb 10 ; 바이트가 10개짜리 있다. 
   