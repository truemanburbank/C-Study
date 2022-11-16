%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    ; 반복문 (while for)
    ; 특정 조건을 만족할 때까지 반복해서 실행
    
    ; ex) Hello World를 10번 출력해야 한다면?
    
    ;mov ecx, 10
 
;LABEL_LOOP:
    ;PRINT_STRING msg
    ;NEWLINE
    ;dec ecx ; sub ecs, 1과 동일
    ;cmp ecx, 0
    ;jne LABEL_LOOP
    
    
    ; 최종 목적 변수를 정하고, 다른 변수 두 개를 0으로 초기화
    ; 그 중 하나를 1씩 증가시키면서 다른 한 변수에 더함
    ; 그 후 증가시키는 변수가 최종 목적 변수와 같으면 반복 중
    ; 거꾸로 100부터 1까지 더해도 됨 
    ; 연습 문제) 1에서 100까지의 합을 구하는 프로그램
   mov ecx, 100 ; 최종 목적
   xor eax, eax
   xor ebx, ebx
LABEL_LOOP:
    inc ebx ; add bx, 1과 동일 
    add eax, ebx
    cmp ebx, ecx
    jne LABEL_LOOP
    PRINT_DEC 4, eax
    NEWLINE
    ;---------------------------------------------------------------  
    ; loop [라벨]
    ; - ecx에 반복 횟수
    ; - loop 할 때마다 ecx 1 감소, 0이면 빠져나감, 아니면 라벨로 이동
    
    mov ecx, 100
    xor ebx, ebx ; 결과
LABEL_LOOP_SUM:
    add ebx, ecx
    loop LABEL_LOOP_SUM
    PRINT_DEC 4, ebx
    NEWLINE
                                                                                                                                                                                                                                                                                                                                                                                                               
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    xor rax, rax ; == mov rax, 0
    ret
    
    ; 초기화된 테이터
    ; [변수 이름] [크기] [초기값]
    ; [크기byte] db(1) dw(2) dd(4) dq(8)
section .data     
    msg db 'Hello World' , 0x00
                  
    ; 초기화되지 않은 데이터
    ; [변수 이름] [크기] [개수]
    ; [크기byte] resb(1) resw(2) resd(4) resq(8)
section .bss
    num resb 1
   