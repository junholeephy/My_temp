#ifndef add_h
#define add_h
class add
{
	private:
		double a;
		double b;

	public:
		add(double a1, double a2);
		virtual double AddM();
};
#endif 


#ifdef add_cxx
add::add(double a1, double a2)
{
	this->a=a1;
	this->b=a2;
}
#endif

