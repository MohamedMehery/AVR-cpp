SRC=$(TARGET).cpp
compile: $(SRC)
	avr-g++ -mmcu=atmega32 -Os -o $(TARGET).o $(SRC)
	avr-objcopy -j .text -j .data -O ihex $(TARGET).o $(TARGET).hex
	@echo "Success compile"
	@ls

clean:
	@rm $(TARGET).hex $(TARGET).O
	@echo "DONE"