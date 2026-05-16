## stroustrup-PPP2
PPP2 breaks many promises it makes throughout the chapters, has many language breaking code, and poorly explains some topics - although that could be just me not understanding. I highly recommend getting PPP3 instead of PPP2 if you are interested in C++ and don't have PPP2 already.

At the time of writing this, I'm going through chapter 12, 13, 14, and 15 trying to fix Bjarne's [graphics interface library](https://www.stroustrup.com/Programming/GUI.tar) so I can continue reading the book. This graphics interface library is introduced in chapter 12 and it breaks many language rules. For example, it tries to change the access level of an inherited constructor via a `using` declaration which is impossible.
