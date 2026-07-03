exe: main.o stud_add.o stud_mod.o stud_show.o load_data.o stud_del.o stud_save.o stud_sort.o
	cc main.o stud_add.o stud_mod.o stud_show.o load_data.o stud_del.o stud_save.o stud_sort.o -o exe

main.o: main.c header.h
	cc -c main.c

stud_add.o: stud_add.c header.h
	cc -c stud_add.c

stud_mod.o: stud_mod.c header.h
	cc -c stud_mod.c

stud_show.o: stud_show.c header.h
	cc -c stud_show.c

load_data.o: load_data.c header.h
	cc -c load_data.c

stud_del.o: stud_del.c header.h
	cc -c stud_del.c

stud_save.o: stud_save.c header.h
	cc -c stud_save.c

stud_sort.o: stud_sort.c header.h
	cc -c stud_sort.c

clean:
	rm -f *.o exe
