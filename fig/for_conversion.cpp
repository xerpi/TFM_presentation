void CodeGen_MLIR::Visitor::visit(const For *op) {
	mlir::Value min = codegen(op->min);
	mlir::Value max = builder.create<mlir::arith::AddIOp>(min, codegen(op->extent));
	mlir::Value lb = builder.create<mlir::arith::IndexCastOp>(builder.getIndexType(), min);
	mlir::Value ub = builder.create<mlir::arith::IndexCastOp>(builder.getIndexType(), max);
	mlir::Value step = builder.create<mlir::arith::ConstantIndexOp>(1);

	mlir::scf::ForOp forOp = builder.create<mlir::scf::ForOp>(lb, ub, step);
	{
		mlir::OpBuilder::InsertionGuard guard(builder);
		builder.setInsertionPointToStart(&forOp.getLoopBody().front());

		mlir::Value i = forOp.getInductionVar();
		sym_push(op->name, builder.create<mlir::arith::IndexCastOp>(max.getType(), i));
		codegen(op->body);
		sym_pop(op->name);
	}
}
