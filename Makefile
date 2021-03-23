CC=gcc
COMPILE=$(CC) -g
CFILES=$(dir \s *.c*)
OBJECT=main.o BattleField.o Vector.o
TARGET=launch
$(TARGET):$(OBJECT)
	$(COMPILE) -o $@ $(OBJECT)
.c:.o
	$(COMPILE) -c $< -o $@
clean:
	del $(TARGET).exe $(OBJECT)