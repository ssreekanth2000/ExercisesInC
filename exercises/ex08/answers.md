*1*
*a*

Where is GLib from and why does it exist? Who uses it, and for what? Would it have been better if they had given it a name less likely to be confused with glibc?



GLib was separated from GTK , a GUI framework, for use in non-GNOME applications.
GLib's code was separated from GTK, so it can be used by software other than GNOME and has been developed in parallel ever since. 
It is used by GNOME and others for general functionality and advanced data structures which are the non-GUI parts of GTK.
GLib provides advanced data structures, such as memory chunks, doubly and singly linked lists, hash tables, dynamic strings and string utilities, such as a lexical scanner, string chunks (groups of strings), dynamic arrays, balanced binary trees, N-ary trees, quarks (a two-way association of a string and a unique integer identifier), keyed data lists, relations, and tuples. Caches provide memory management. 
 
 
 *b*
 
 What are the most important pros and cons of using GLib, as opposed to another library, or just using core C features?
 
 It has more data structures compared to similar things like APR. A con is that it uses static compilation.
 
 
 *c*
 
 What do you have to do to compile and run a “Hello GLib” example?
 
 gcc -Wall -o ex_compile ex_compile.c $(pkg-config --cflags --libs glib-2.0)
 ./ex_compile
