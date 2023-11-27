import hamming_distance_module

hdc = hamming_distance_module.HammingDistanceCalculator()
distance = hdc.compute("string1", "string2")
print("Hamming Distance:", distance)
