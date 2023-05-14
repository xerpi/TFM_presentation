void CodeGen_MLIR::Visitor::visit(const IntImm *op) {
	mlir::Type type = mlir_type_of(op->type);
	mlir::IntegerAttr val = builder.getIntegerAttr(type, op->value);
	value = builder.create<mlir::arith::ConstantOp>(type, val);
}
