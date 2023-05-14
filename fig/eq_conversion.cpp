void CodeGen_MLIR::Visitor::visit(const EQ *op) {
	if (op->a.type().is_int_or_uint())
		value = builder.create<mlir::arith::CmpIOp>(mlir::arith::CmpIPredicate::eq,
		                                            codegen(op->a), codegen(op->b));
	else if (op->a.type().is_float())
		value = builder.create<mlir::arith::CmpFOp>(mlir::arith::CmpFPredicate::OEQ,
		                                            codegen(op->a), codegen(op->b));
}
