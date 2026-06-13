## stroustrup-PPP2
PPP2 breaks many promises it makes throughout the chapters, has many language-violating code, and poorly explains some topics—although that could be just me not understanding. I highly recommend getting PPP3 instead of PPP2 if you are interested in C++ and don't have PPP2 already.

That said, this [graphics interface library](https://www.stroustrup.com/Programming/GUI.tar) is introduced in chapter 12, and it violates many language rules. For example (just to mention one), it tries to change the access level of an inherited constructor via a `using` declaration, which is impossible. So, I have gone through chapters 12-16 and fixed it. You can find the fixed library [here](lib/Simple_Interface) and use it to follow along with the book.
