OUTPUT=sixth
CFLAGS=-Wall -Werror -fsanitize=address

%: %.c
	gcc $(CFLAGS) -o $@ $<

%: %.c %.h
	gcc $(CFLAGS) -o $@ $<

all: $(OUTPUT)

clean:
	rm -f *.o $(OUTPUT)