import tanimoto_coefficient_module

tcc = tanimoto_coefficient_module.TanimotoCoefficientCalculator()
coefficient = tcc.compute([True, False, True], [True, True, False])
print("Tanimoto Coefficient:", coefficient)
