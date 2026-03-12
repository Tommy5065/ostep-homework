![alt text](image.png)
The use radio of CPU is 100%,because two processes run totally run 10 instructions that are divided 5 instruction for one process.Each one instruction uses CPU no issuing IO. 
![alt text](image-1.png)
One process wait other process which issuing an IO needs 11 seconds,because of  an IO finished taking 5 seconds.
![alt text](image-2.png)
PID1 are using CPU when PID0 is waiting IO finished,whether IO before CPU is important,because it decides CPU is used or free.
![alt text](image-3.png)
Now we use option -S SWITCH_ON_END,when PID0 is issuing IO,CPU not change to run PID1,so CPU is free.
![alt text](image-4.png)
Now we use option -S SWITCH_ON_IO,when PID0 is issuing IO,CPU runs PID1,so CPU is used.
![alt text](image-6.png)
If we use -I IO_RUN_LATER,which means IO finished that don't immediately runs the process,until PID1,PID2,PID3 is finishing.
![alt text](image-7.png)
If we use -I IO_RUN_IMMEDIATE,which means IO finished that immediately runs the process, PID1,PID2,PID3 meanwhile use CPU,completing CPU use raio is 100%.
![alt text](image-8.png)
![alt text](image-9.png)

