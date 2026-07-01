## Objects, types, and values

An _Object_ is a region in memory with a type.  
A named object is called a _variable._  
An object’s type specifies what value can be stored in the object, and what operations can be done on the value.

A _whitespace_ is a space, a newline, or a tab.

A program is _type-safe_ when it uses types according to their rules.
_Narrowing conversions_ happened when values, when converted, they lose data (e.g., float to int).

We prefer _universal and uniform initialization `{}`,_ but we use `=` out of habit.

## Computation

_Computation_ is taking input(s) and giving output(s) based on the input(s).

> All that a program ever does it to compute.

When we say “input/output” we usually mean input/output to/from a program, but it could be to/from parts of a program (functions).

Inputs to parts of a program are called _arguments._  
Outputs from parts of a program are called _results._

Our job as programmers is to compute, _correctly,_ _simply,_ and _efficiently._  
The way to organize a program is to break up big computations into many little ones. This can be done by _abstractions,_ and _divide and conquer._

> We humans, can't deal with big problems unless we break them into many little ones.

An _expression_ computes a value from a set of operands using operators.  
A _constant expression_ is an expression, but the operands are constants.  
The simplest expressions include: `1`, `'a'`, `"Asian women"`, `3.14`.

A _statement_ is an instruction to a computer.  
Statements include: expressions, declarations, if-statements, for-statements, while-statements, etc.  
An _empty statement_ is a statement that doesn't have a body. An example includes: `while(...);`.

There's no such thing as “else-if-statements” in C++. The form goes:

    if (expression) statement else statement

in else's statement you can put another if-statement.

The value we switch must be a `char`, `int`, or `enumeration`.  
The case label values must be constants.

Doing something several times is called _repetition_ or — iteration when you go through a set of elements.

while-statements poorly manage their _loop/control variable._

A _compound-statement/block_ is a sequence of statements delimited by curly-braces.  
A _vector_ is a sequence of elements accessed by an index.

A _function_ is a named sequence of statements.  
If a computation is a worthy of a name, it should be a function.  
Every function should do a single logical action.  
Functions should reflect the structure of a program, and describe the logically separate parts.

range-for-statements are only used to iterate over a sequence in order. For more sophisticated iterations use for-statements.

## Errors

Compile-time errors:

- Syntax errors: not well formed to language grammar.
- Type errors: mismatch between variables, and assigned values (arguments, initializirs, etc.).

Link-time errors: ODR, missing definitions, etc.

Run-time errors: errors found by a running program; that running program could be an OS, library or usercode.

~~Logic errors: Asian women~~.

The callee should detect and report run-time errors, unless there's a reason not to. Such as if the definition is inaccessible.

After detecting a run-time error, how should you report it? You could return an error code (that's what Win32 does), but that has its downfalls. Such as what if you can't find a value that indicates an error code, that now both the callee and the caller need to check, or what if the caller forgets to check? Instead, C++ provide a mechanism for handling errors, called _exceptions._ The callee throws an exception and the a direct or indirect caller catches the exception if interested.

If you try to index an element out of range, the standard container will throw an exception of type std::out_of_range. This error is so famous that it has several names: _off-by_one error,_ _range error,_ and _bounds error._ 

std::runtime_error, and std::out_of_range derive from std::exception.

Narrowing is a logical error. To prevent it, we implement narrow_cast\<type>(value) which throws an exception if narrowing happens or returns the casted value otherwise. Or simply use `{}`.

_Debugging_ is the process of finding and removing bugs. It goes like this:

1. Get the program to compile
2. Get the program to link
3. Get the program to do what it's supposed to do

and repeat until the program is free of errors, or errors we consider unacceptable for it.

The term “bug” is claimed to be originated from old computers where bugs used to enter and ruin their electronics.

> The last bug is a programmers' joke: there's no such creature.

For pre/post conditions refer to [this](https://x.com/mouaamn/status/2019974423160451238).

Imagine your daughter have written a program that computes the area of a rectangle. You run it, and get `-6`. You just know that's wrong. Why? Because no shape has a negative area. So, she fixes the bug, and gets `6`. Now that just might be right. The point here is that unless we have some idea of what a correct answer will be like, we have no clue whether the result is plausible.

> What we must do before making fools of our selves by delivering a program that produces ridiculous results is just to check that the answer is plausible.

_Estimation_ is a noble art that combines common sense and some arithmetic applied to a few facts.  
_Guesstimation_ combines guessing with a bit of calculation.  
Some people are good at doing estimates in their head, but I prefer doing it on a whiteboard.

_Systematic testing_ is executing a program with a large and systematically selected set of inputs and comparing the results with what was expected.  
A run with a set of inputs is called a _test case._  
Systematic testing can't be done by humans.

## Writing a program

In this chapter we write a calculator. Writing one requires experience, a mentor, or literature. People been writing calculators for decades (50+ years), and how to write one has a standard answer.

> Writing a program starts with a problem; that is, a problem you want to write a program to help solve.

First, we tokenize the input to be able to look at it in convenient ways. Then, we write a _grammar_ to teach the program how to understand the input. For example, `2+10/5` is `2+(10/5)` and not `(2+10)/5`. Then, a program that implements the rules of that grammar.

A _token_ is a sequence of characters that represent something we consider a unit.  
_Tokenizing_ is reading characters and assembling them into tokens.  
~The notion of _(name, value)_ pairs.

A program that implements a grammar is called a _parser_ or a _syntax analyzer._

Here's a grammar:

    Expression:
        Term
        Expression "+" Term
        Expression "-" Term
    Term:
        Primary
        Term "*" Primary
        Term "/" Primary
    Primary:
        Number
        "(" Expression ")"
    Number:
        floating-point-literal

The last rule says that “a Number is a floating-point-literal.” The next-to-last rule says that “a Primary is a Number or a `'('` followed by an Expression followed by `')'`.”

Could you articulate an explanation in sufficient detail and precisely enough for a computer to understand how you do `2+10/5`? _Grammar_ is the most powerful tool/notation for that.

---

When you work on a problem you repeatedly go through these stages:

- Analysis: Figure out what should be done and write a description of your understanding of the problem. Such description is called a _set of requirements_ or _specification._
- Design: Create an overall structure for the system, deciding which parts the implementation should have, how these parts should communicate.
- Implementation: Write the code, debug it, and test it.

Here are some suggestions for problem solving: 

- Given specification.
  - Is it clear? Don't be a future creep, and ask too much.
  - Does it sound manageable given the time, skills, and tools available? There's a little point in starting a project you couldn't possibly complete.
- Try breaking the problem into manageable parts.
  - Do you know of any tools, libraries, etc. that might help?
  - Look for parts of the program that can be separately described.
- Build a small initial version the solves the key part of the problem _(prototype)._
- Build a full solution by using parts of the prototype.

_Pseudo code_ describes the main logic of a program.

---

## Completing a program

We made a _prototype_ of a calculator. Now that we have a prototype we can experiment, try out ideas, and come up with a better version.

When we have a program that “works.” We try feeding the program with as much input in the hope of making it misbehave; that is, we try finding errors before somebody else finds them.  
There are people that break “things” for a living, called _testers._

The `%` operator works only on integers, because it doesn't want to duplicate fmod. The fmod function is defined as `x-y*int(x/y)`.

Even the “prompt” and the “result indicator” are considerd magic-constants.

> Code that is hard to read is where bugs can easily hide.

~Why do we exist when an exception is thrown? The notion of recovering from errors.

The mechanism for storing (name, value) pairs is called _symbol table,_ and it's best done using std::map.

As it happens, we have now seen a simple example of how a compiler works. The calculator analyzes input broken down into tokens and understood according to a grammar. That's exactly with a compiler does. After analyzing its input, the compiler then produces a representation (object code) that we can later execute. The calculator immediately executes the expressions it has analyzed; programs that do that are called interpreters rather than compilers.

## Technicalities: functions, etc.

We consider how to express ideas as code far more interesting than the technical details of the programming language that we use to express those ideas. However, we don't always have a choice. Your programming language is a foreign language for which you need to look at “grammar and vocabulary.”

Most programming concepts are universal, but _language-technicalities_ are specific to a given language.

A _declaration_ is a statement that introduces a name into a scope.

  - Specifying a type for what is named (e.g., a function or a variable).
  - Optionally, specifying an initializer (e.g., an initializer value or a function body).

Examples include: `int a = 5;`, `extern int b;` `int foo(int);`.

A declaration that fully specifies the entity declared is called a _definition._  
Examples include: `int a = 5;`, `int b;` `int foo(int n){ return 3*n; };`.

A definition specifies exactly what a name refers to. For example, a definition of a variable supplies the object (the memory). A definition of a function supplies the function body (the excutable statements). So, you can't define twice, but you can declare twice or more.

Built-in types don't have _default-constructors,_ but UDTs do. Tho, global variables are default initialized to `0`.  
A _header_ is a collection of declarations. When those declarations are alone in a file. We call it a _header file._

The main reason you don't want global variables is because it's hard to keep track of who modifies a global variable. Also, because the order of initialization of global variables in different translation units is undefined. A good program will have one, two or even none, global variables. [See](https://pastebin.com/hDGavP3V).

A const-reference doesn't require an lvalue. So that:

    void foo(const int& cr);

    foo(3); // means: __compiler_generated = 3; foo(__compiler_generated);

such a compiler-generated object is called a _temporary object,_ or just a _temporary._

When a function is called, the language implementation sets aside a data structure, called _function-activation-record,_ containing a copy of all its parameters, and local variables (the implementation considers parameters, local variables). For example, consider the previous code fragment:

    ╔═════════════════════╗
    ║cr                   ║
    ║Implementation stuff ║
    ╚═════════════════════╝

each time we call a function, the “stack of activation records” or just called a “stack,” grows by one. It follows the rule “Last in, first out.” The “Implementation stuff” varies from implementation to implementation, but it basically has the information needed for a function to return to its caller or return a value to its caller.

A constexpr function may not have _side effects._  
Destruction happens in the reverse order of construction.

A name composed of a namespace (or a class name) and a member-name combined using `::`, is called a _fully qualified name._ This doing is called “qualification.”

    using std::string; // a using declaration
    using namespace std; // a using diractive

## Technicalities: classes, etc.

A type is called “built-in” if the compiler knows how to represent objects of the type, and which operations can be done on it without being told by declarations supplied by a programmer in source-code.

User defined types (UDTs) include the ones in the standard library, and the ones you will declare once you get the technicalities under your belt. We consider the standard library types, UDTs, because they are built from the same primitives and with the same techniques we use to build UDTs; the standard library builders don't have special privileges that you don't have.

The help from a type, comes in two forms:

- Representation: the data that represents an object — called its “current state/value.”
- Operations.

C++ provides two kinds of UDTs: _classes_ and _enumerations._  
If you think of something as a separate entity, it's likely that you should define a class to represent that “thing.” A class should always represent a concept; that is, it shouldn't be just a collection of data and functions.

Usually, we think of a class as having an _interface_ plus an _implementation._ The users can access the interface directly, but the implementation indirectly through the interface. The interface is identified by the label `public:`, and the implementation by the label `private:`.  
We put the interface first, because it's what most people are interested in.

> Everything that's tedious is error-prone!

In C++98, people used `()` to delimit an initializer list.  
Member functions can't be forgotten or overlooked, especially constructors.  
The `: y{ yy }, m{ mm }, d{ dd }` is called a _member initializer list._

We desgin our types so that values/states are guaranteed to be valid. The notion of a _valid value (or state)_ of an object.  
What constitutes a valid value is called an _invariant._  
What does it mean for a value to be valid (what is the invariant)?  
If you can't think of an invariant, you are probably dealing with plain data. If so, use a struct.

Writing a member function definition within a class definition has two primary effects:

- The function will be _inline._
- The class definition grows larger.

An _enum_ (called an enumeration) is a UDT that specifies a set of symbolic constants (called _enumerators_).  
There are two types of enums:

- enum classes (also called “scoped enumerations”).
- plain enums.

Prefer enum classes over “plain” enums, and expect seeing “plain” enums in older code, because they were introduced in C++11.

Overload operators only when you are certain that you need them. Also, define them only with their conventional meaning. For example, `+` should do addition. So, you don't confuse others.

There are two conventions in writing dates:

- Day-Month-Year (DMY): UK.
- Month-Day-Year (MDY): USA.

A const object can only call const member functions, because they promise to not modify a representation.

Keep interfaces minimal (though complete), because a small interface is easier to learn and comprehend. A member function that can be implemented as a free-standing, helper function, should be implemented as so. Note: not letting a lot of access to a representation is important.

_Helper functions_ take arguments of the classes they are helper of. Helper functions are also called _convenience functions_ and _auxiliary functions._ Helper functions are a design concept.

## Input and output streams

Most operating systems separate the detailed handling of I/O devices into _device drivers,_ and programs then access the device drivers through an I/O library that makes I/O from/to different sources appear as similar as possible.

Without device drivers we would have to directly address each kind of device on the market, in our programs.

    input device -> device driver -> input library -> our program -> output library -> device driver -> output device

With a model like this, input and output can be seen as streams of bytes handled by the input/output library.

An _ostream_ turns values of various types into a sequence of characters. Then sends it somewhere, and that “somewhere” could be a file, a console, the main memory, or another computer.

An _istream_ composes values of various types from a sequence of characters. It gets those characters from “somewhere.”

Input and output are first stored in a _buffer_ — it's like a staging phase.

With an istream, the buffering can be quite visible to the user. When you use an istream that is attached to a keyboard, what you type is left into the buffer, and you can use “backspace” to change your mind, until you hit enter.

A _file_ is simply a sequence of bytes numbered from 0 and upward.  
A file has a _format;_ that is, it has a set of rules that determine what the bytes mean. For example, if we have a text file, the first 4 bytes will be the first four characters.

> We can make sense of bits in a file only if (and only if) we know the file's format.

When a file stream goes out of scope, its associated file is closed. When a file is closed, its associated buffer is “flushed;” that is, the characters from the buffer are written to the file.  
Opening the file using a constructor, and relying on the destructor to take care of closing the file is the ideal.

The reasons for input operations failing are limitless, but the std::istream limits them to four cases, called the _stream state:_

- good
- eof
- fail
- bad: something serious happened

If an input operation encounters a simple format error, it lets the stream `fail()`, assuming that you might be able to recover, or throws an exception if there's no chance of recovery. On the other hand, if something really nasty happens, such as a bad disk read, the input operation lets the stream go `bad()`.  
If the stream is bad it's also fail.

The main design problem with overloading output operators is that different people might prefer the output look different.

    cout << 2 << 4; // means: operator<<(operator<<(cout, 2), 4);

Overloading an input operator is basically an exercise in error handling.

File formats are often peculiar, and we don't always have the freedom to choose a file format. If a format is too awful, we could write a format-conversion program, or simply just deal with that awful format. After all, files are just the way they are, and we have to deal with them.

## Customizing input and output

As programmers we, prefer _regularity;_ treating all objects and input sources equivalently, and imposing a single standard on how to represent objects entering and exiting the system give the cleanest, simplest, most maintainable, and often the most efficient code.

Hexadecimal is popular for outputting hardware related information. The reason is that a hexadecimal digit exactly represents a `4` bit value. Thus, two represent a byte, four represent two bytes (half a word), and eight represent four bytes (a word or a rigster). When C was first designed, octal was popular, but now it's rarely used.

The “tab” character stands for “tabulation character.”

std::hex, std::dec, std::oct, std::showbase, std::noshowbase are called _manipulators,_ and they stick/persist. Though, not all manipulators persist. Take `setw()` as an example.

Seeing a value without a base can be confusing. For example, the decimal `11` is `13` in octal.  
Decimals don't have a base, hexadecimals have `0x` or `0X`, and octals have `0`.

std::defaultfloat chooses between std::fixed, and std::scientific based who gives the most accurate representation.  
_Precision_ is `6` by default, and its meaning depends:

- defaultfloat: precision is the total number of digits.
- fixed and scientific: precision is the number of digits after the decimal point.

When output doesn't fit on a field (it's considered an overflow), the ostream breaks the output format. Bad formatting is always preferable to “bad output data.”

What a stream associated to a file can do, depends on its modes (properties).

When moving from character-oriented I/O to _binary I/O_, we give up our `<<` and `>>` operators, because they turn values into character sequences. We use `write()` and `read()` instead.

Every file opened for reading has a _read/get position,_ and every file opened for writing has a _write/put position._  
It's undefined to seek beyond the end of a file.

## A display model

The iostream library is oriented toward reading and writing streams of characters. The only supported graphical notion is the notion of “graphical position” that is supported using the newline and tab characters. You can embed notions of color, two-dimensional positions, etc. in one-dimensional stream of characters using _typesetting and markup languages_ such as TeX, LaTeX, HTML, etc.

The connection between characters written using those languages and what appears on the screen is indirect, governed by a program that interprets those commands. On the contrast, the notion of graphics is direct correspondence between the objects in memory and the images on the screen. For example, a Circle object is a circle on the screen.

The model is as follows: we create objects (such as a Square) from basic objects provided by a graphics system (such as a Line). We attach those graphics objects to a Window object. Then a program we can think of as “display engine” or as “GUI library” takes the objects attached to our window and draws them on the screen. The GUI library delegates most of its work to the OS.

We use a GUI library/toolkit called “FLTK” to support all operating systems, and we use simple interface classes to simplify FLTK.

    Our code -> Our interface library -> A graphics/GUI library (FLTK) -> The operating system -> Our screen.

A _computer screen_ is a rectangular area composed of pixels.  
A _pixel_ is a tiny spot that can be given a color.  
A _Window_ is a rectangular region of a screen devoted to some specific purpose, and controlled by a program.  
The area of a window that you can draw on is referred to as a _canvas,_ and sometimes as “the inside of a window.”  
Some screens have bigger pixels than others.

Line, Lines, Polygon, Axis, Rectangle, Text, and Image, all derive from Shape — directly or indirectly.
Simple_window derive from Window.  
Shape is called a _base class_ for them, and they are called _derived classes._ For example, Shape is a “base” of Line.

A lot of the shapes in our modern world are rectangles, because it's the simplest shape to deal with. For example, it's easy to describe a rectangle, it's easy to tell whether a point is inside a rectangle or outside it, it's easy to get hardware to draw a rectangle of pixles fast. So, that's why rectangle UDTs are usually defined separately. Rectangles are special in that they are easy to draw.

Making a rectangle by placing points in the right places isn't enough to make a rectangle. For example, a Polygon doesn't represent a Rectangle in memory — adding a fifth point proves it. The same thing applies to making a Polygon using a Closed_polyline — adding a point that makes an intersectional line proves it. And the same thing applies to making a circle using an ellipse by making `major = minor` — changing either proves it.

## Graphics classes

Graphics and GUI libraries provide lots of facilities. By “lots” we mean hundreds of classes, and often functions for each. Reading a documentation is daunting! It can also be exciting — looking at the facilities can make you feel like a child in a candy store.

One purpose of our interface classes is to reduce the shock delivered by a full graphics/GUI library.

You can only change the access-level of non-constructors with `using-declarations`. You can also use them to introduce members into a scope.

“Poly” is a Greek word for “many.” A Closed_polyline connects the last Point with the first, where as an Open_polyline doesn't.

std::vector has a default constructor, and a std::initializer_list constructor.  
Vector_ref stores named and unnamed objects.

The reason for restricting Text's string to be a single-line is to ensure portability across systems. Don't try to put `\n` as it's undefined.

## Graphics class design

Our ideal is a minimal interface that allows us to do what we want. We also want our interfaces to have a common, style; that is, the same operations having the same name, taking arguments of the same types, and in the same order.

Shape's constructors are all _protected._ That means they can only be used by derived classes. In other words, Shape can only be used as a base for classes. The purpose is to ensure that we can't create Shape objects directly. Think about it! What does a shape look like? The only reasonable response is the counter question “What shape?” Shape is an abstract concept.

A class is _abstract_ if it can be used only as a base class.  
A class that can be used to create objects; that is, the opposite of an abstract class, is called a _concrete_ class.

Note that “abstract” and “concrete” are simply technical words for everyday distinction. We might go to the store to buy a camera. However, we can't just ask for a camera and take it home. What brand of camera? Which particular model camera? The word “camera” is a generalization; it refers to an abstract notion. An Olympus E-M5 refers to a specific kind of camera, which we might acquire a particular instance of: a particular camera with a unique serial number. So “camera” is like an abstract (base) class; “Olympus E-M5” is much like a concrete (derived) class, and the actual camera in my hand would be much like an object.

_Virtual functions_ is the ability to define a function in a base class, and have a function of the same name and type in a derived class called when a user calls the base class function. This is often called _run-time polymorphism,_ dynamic dispatch, or run-time dispatch, because the function called is determined at run-time.

Circle consist of two parts: Shape and Circle. Imagine copying only the Shape part. That's called _slicing._ The Circle part is sliced off. That's why we disable copy operations for base classes. [See](https://pastebin.com/VwgDvMFR).

_Derivation_ is away to build one class from another so that the new class can be used in the place of the original. This is often called _inheritance,_ because the derived class (also called “subclass”) inherits all the members of its base (also called “superclass”).

Inheritance, run-time polymorphism, and encapsulation is the most common definition of object-orinted programming.  
C++ supports other programming styles other than OOP such a as _generic programming._  
C++ borrowed its key mechanisms from Simula67 ([67](https://www.youtube.com/watch?v=L7ejl_Hj3A8)), the first language to directly support OOP.

One more piece of data is added to an object of a class with virtual functions: a pointer called `vptr` pointing to an address of a static `vtbl` that contains the virtual functions. For example, a Circle inherits from Shape which has 2 virtual functions, and then it overrides one. So the `vtbl` would look like this:

    ╔═════════════════════╗
    ║Circle::draw_lines   ║
    ║Shape::move          ║
    ╚═════════════════════╝

Each object of Circle will have its own `vptr` pointing to the same `vtbl`. [See](https://x.com/mouaamn/status/2040044852579295372).

Defining a function of the same name and type of a virtual function from a base class so that the function from the derived class is put into the `vtbl` instead of the version from the base is called _overriding_.

Functions must be declared `virtual` only in class declaration.  
`struct Foo : Doo` is by default public derivation, but `class Foo : Doo` is by default private derivation. The base is said to be a public or a private base. Though you could be explicit by specifying `public` or `private` keyword.

You can get the compiler to check if a function overrides or not by using the `override` keyword.

If you want to become a language lawyer you need to study Stroustrup, The Design and Evolution of C++ and The C++ Programming Language, and the ISO C++ standard. We don't recommend becoming a language lawyer (someone knowing every little detail of the language definition); being a programmer (whatever you call someone who actually uses the language) is much more fun and typically much more useful to society.

One way to make an abstract class is by making its constructors protected. Another, is by making _pure virtual functions_. A pure virtual function only adds `= 0;` to a virtual function declaration. A derived class must override all pure virtual functions or else it will become abstract too.

If a base of class D is private, its public and protected members can be used only by members of D.  
If a base of class D is protected, its public and protected members can be used only by members of D, and members of classes derived from D.  
If a base is public, its public members can be used by all.

We want derivation for two reasons:

- Interface inheritance: a function expecting a Shape can accept a Circle, and use Circle through the interface of a Shape.
- Implementation inheritance: we can use the facilities offered by Shape.

> Classes, inheritance, encapsulation, and run-time polymorphism are among the most powerful tools for structuring systems.

## Graphing functions and data

The following is a type alias for a function pointer:

    using Fct = double (*)(double);

Consider the following code fragment:

    std::function fct{ [](double x) { std::cout << x << '\n'; } };

the `[](double x) { std::cout << x << '\n'; }` is a _lambda expression;_ that is, it's an unnamed function. The `[]` is called a _lambda introducer,_ it can capture a name, but when it does, it can't convert to a function pointer. After the lambda introducer, the lambda expression specifies what arguments are required, and what actions to be performed. The return type can be deduced from the lambda body, but you can explicitly specify it: `[](double x) -> double { std::cout << x << '\n'; }`. Tho, the ideal is not to.

> Displaying data is a highly skilled and valued craft. When done well, it combines technical and artistic aspects and can add significantly to our understanding of complex phenomena.

Adjacent string literals such as `"Mouaamn's unclear " "destiny."` get concatenated by the compiler.

## Graphical user interfaces

Every program has a user interface. For example, a calculator's UI is its buttons and screen. For a user like you who has a monitor, a keyboard, and a pointing device, the interface can be of three:

- console user interface (CUI): iostreams.
- graphical user interface (GUI): Win32, FLTK.
- web user interface (WUI): HTML, and usually a scripting language.

A _callback function_ is a function you give (e.g., to a GUI system) to be called later.

A GUI system like FLTK (and the operating system) can be used by programs written in a variety of languages. So, it can't impose C++ styles on all users. In particular, it does not know about our Simple_window class or our Button class. In fact, it doesn't know about classes or functions at all. The type required for a callback function is chosen so that it's usable from the lowest level of programming including C and assembly. A callback function returns no value and takes two addresses as its arguments. We can declare a C++ member function that obeys those rules like this:

    static void cb_next(Address, Address pw) 
    // address of the widget which triggered the callback 
    // address of the window containing the widget 
    {
        reference_to<Simple_window>(pw).next();
    }

The Address type specifies an address of “something in memory.” We are so close to the hardware and don't get the usual help from the language, so we can't use C++ references here. The `reference_to<Simple_window>(pw)` casts the raw address to a `Simple_window&`.

Yes, _widget_ really is a technical term. A more descriptive, but less evocative, name for a widget is a _control._ We use widgets to define forms of interactions (e.g., button) with a program through GUI. [See](https://learn.microsoft.com/en-us/windows/win32/controls/window-controls).

If you forget to name a local variable, the compiler will delete it, assuming that you aren't making use of it.

When code is managed by a GUI system, a thrown exception may never find a handler, because the GUI system or the operating system may be oblivious to C++ exceptions; that is, it could be “eaten.”

GUI is a huge topic. Much of it has to do with style and compatibility with existing systems. Furthermore, much has to do with a bewildering variety of widgets (such as a GUI library offering many dozens of alternative button styles) that would make traditional botanist feel quite at home. One thing you should be aware of is that most GUI systems provide a “GUI builder” that allows you to design your window layouts graphically and attach callbacks and actions to buttons, menus, etc. specified graphically. It's worth using to reduce the tedium of writing “scaffolding code.”

## Vector and free store

