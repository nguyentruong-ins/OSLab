all:
	gcc -pthread pi_serial.c -o pi_serial
	gcc -pthread pi_multi-thread.c -o pi_multi-thread
	./pi_serial 1000000
	./pi_multi-thread 1000000
	make clean	
clean:
	rm pi_serial pi_multi-thread
