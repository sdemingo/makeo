# What is Makeo

It's a really simple stack-based virtual machine and a intermediate
language interpreter named IL. Now, I'm preparing a reference of this
intermediate language and working on a compiler to get IL code from a
high-level language called MK. 

This work was inspired by reading "The Elements of Computing Systems:
Building a Modern Computer from First Principles" and It has not a
particular target and I have made it, just for fun. If you want to
help me and learn some things about compilers, of course, you are
invited ;-)

	
# Install

To install Makeo properly you only need to use the followings
commands:

```
git clone https://github.com/sdemingo/makeo.git
cd makeo
make
make clean
MKPATH=`pwd`
export MKPATH
```

# Executing MK programs

MK is a simple high-level programing language. Before you can execute
a program, you must compile it. To compile a MK program you have to
use the mkc tool. This tool compile your MK code into a IL or
intermediate code based on commands to a stack-based virtual machine.

To compile a MK code use mkc tool:

```   
$ mkc examples/program.mk -o /tmp/program.il
```

Now, you can run your program with mkm tool:

```
$ mkm /tmp/program.il
```

You can use the following flags with mkm:

    -v: print all line read from the input

    -m: print all symbols on the symbol table with theirs values


