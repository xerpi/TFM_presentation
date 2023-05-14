void CodeGen_MLIR::Visitor::visit(const Add *op) {
	if (op->type.is_int_or_uint())
		value = builder.create<mlir::arith::AddIOp>(codegen(op->a), codegen(op->b));
	else if (op->type.is_float())
		value = builder.create<mlir::arith::AddFOp>(codegen(op->a), codegen(op->b));
}
