void CodeGen_MLIR::Visitor::visit(const Load *op) {
	Expr index;
	if (op->type.is_scalar())
		index = op->index;
	else if (Expr ramp_base = strided_ramp_base(op->index); ramp_base.defined())
		index = ramp_base;
	else
		user_error << "Unsupported load.";

	mlir::Value baseIndex = sym_get(op->name);
	mlir::Value indexI64 = builder.create<mlir::arith::ExtUIOp>(builder.getI64Type(), codegen(index));
	mlir::Value address = builder.create<mlir::arith::AddIOp>(baseIndex, indexI64);
	mlir::Value addrIdx = builder.create<mlir::arith::IndexCastOp>(builder.getIndexType(), address);

	mlir::Value buffer = sym_get(op->name + ".buffer");

	if (op->type.is_scalar())
		value = builder.create<mlir::memref::LoadOp>(buffer, mlir::ValueRange{addrIdx});
	else
		value = builder.create<mlir::vector::LoadOp>(mlir_type_of(op->type), buffer, mlir::ValueRange{addrIdx});
}
