struct IfThenElse : public StmtNode<IfThenElse> {
	Expr condition;
	Stmt then_case, else_case;

	static Stmt make(Expr condition, Stmt then_case, Stmt else_case = Stmt());

	static const IRNodeType _node_type = IRNodeType::IfThenElse;
};
