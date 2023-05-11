struct IntImm : public ExprNode<IntImm> {
	int64_t value;

	static const IntImm *make(Type t, int64_t value);

	static const IRNodeType _node_type = IRNodeType::IntImm;
};
