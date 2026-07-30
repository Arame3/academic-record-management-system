#include "pch.h"
#include "Student.h"

TEST
(
	StudentTests,
	ParameterizedConstructorStoresValidValues
)
{
	Student student(1, "Arame", 95.5);

	EXPECT_EQ(student.getId(), 1);
	EXPECT_EQ(student.getName(), "Arame");
	EXPECT_DOUBLE_EQ(student.getScore(), 95.5);
}

TEST
(
	StudentTests,
	ParameterizedConstructorReplacesInvalidValues
)
{
	Student student(-5, "", 120.0);

	EXPECT_EQ(student.getId(), 0);
	EXPECT_EQ(student.getName(), "Unknown");
	EXPECT_DOUBLE_EQ(student.getScore(), 0.0);
}