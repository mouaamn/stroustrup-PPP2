/*
	Note: Honestly, IDK, this topic is poorly explained by the author.
	It's like the chapter was written with little thought into it.

	Expression:
		OR_Expr	
	OR_Expr:
		XOR_Expr	
		OR_Expr "|" XOR_Expr
	XOR_Expr:
		AND_Expr
		XOR_Expr "^" AND_Expr
	AND_Expr:
		Unary
		AND_Expr "&" Unary
	Unary:
		Integer
		"!" Unary
		"~" Unary
	Integer:
		"int"
*/