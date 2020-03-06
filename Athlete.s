.name "Athlete1"
.comment "Keep running boy but not too fast"

start:
	sti r1, %:aliveloop, %1		; %1 to 1 for syntax test
    live %1
	fork %:continue
	and r1, %0, r1
boom2:
	ld %0, r5					; r5 to %5 for syntax test
	sti r1, %:aliveloop, %1
	live %1
	sti r5, -500, %:start
	sti r5, -490, %:start
	sti r5, -480, %:start
	sti r5, -470, %:start
	sti r5, -460, %:start
	sti r5, -450, %:start
	sti r5, -440, %:start
	sti r5, -430, %:start
	sti r5, -420, %:start
	sti r5, -410, %:start
	sti r5, -400, %:start
	zjmp %:boom2

aliveloop:
	live %1
	zjmp %:aliveloop

continue:
	sti r1, %:aliveloop2, %1
	live %1
    fork %:continue2  
	and r1, %0, r1

aliveloop2:
   	live %1
	zjmp %:aliveloop2

continue2:
	sti r1, %:aliveloop3, %1
	live %1
	fork %:continue3
	and r1, %0, r1

aliveloop3:
   	live %1
	zjmp %:aliveloop3

continue3:
	sti r1, %:aliveloop4, %1
    live %1
    fork %:attack
	and r1, %0, r1

aliveloop4:
	live %1
	zjmp %:aliveloop4

attack:
	and r1, %0, r1
	zjmp %:boom
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	sti r1, %next, %1
next:
	live %1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	sti r1, %next2, %1
next2:
	live %1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
	and r1, %0, r1
boom:
	sti r1, %next2, %1
next2:
	live %1
	ld %0, r5
	sti r5, 500, %:end
	sti r5, 490, %:end
	sti r5, 480, %:end
	sti r5, 470, %:end
	sti r5, 460, %:end
	sti r5, 450, %:end
	sti r5, 440, %:end
	sti r5, 430, %:end
	sti r5, 420, %:end
	sti r5, 410, %:end
	sti r5, 400, %:end
	fork %:start
	zjmp %:boom
end:
	aff r1