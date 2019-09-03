add_executable(sequence.t 
	array.t.cpp
	binop.t.cpp
	cartesian.t.cpp
	concatenate.t.cpp
	counted.t.cpp
	drop.t.cpp
	factorial.t.cpp
	filter.t.cpp
	flatten.t.cpp
	fmap.t.cpp
	fold.t.cpp
	merge.t.cpp
	null.t.cpp
	pointer.t.cpp
	power.t.cpp
	reverse.t.cpp
	scan.t.cpp
	sequence.t.cpp
	singleton.t.cpp
	zip.t.cpp
)
target_compile_features(sequence.t PRIVATE cxx_std_17)
add_test(NAME sequence_test COMMAND sequence.t)
