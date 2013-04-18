template<class Type>
class HASH
{
public:
	virtual int find(Type x)const=0;
	virtual bool insert(Type x)=0;
	virtual bool remove(Type x)=0;
};
