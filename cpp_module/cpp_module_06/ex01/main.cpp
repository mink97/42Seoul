#include "Serializer.hpp"

int main()
{
	Data d1;
	Data* d1Ptr = &d1;
	uintptr_t d1Serial;

	d1.data = "mingkang";
	d1Serial = Serializer::serialize(d1Ptr);
	std::cout << d1Serial << std::endl;
	std::cout << d1Ptr << std::endl;
	std::cout << Serializer::deserialize(d1Serial) << std::endl;
	std::cout << d1Ptr->data << std::endl;
	std::cout << Serializer::deserialize(d1Serial)->data << std::endl;
}
