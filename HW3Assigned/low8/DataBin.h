#ifndef DATABIN_H_
#define DATABIN_H_
class DataBin {
public:
   DataBin(int _datum); 
   virtual int getDatum( );

   virtual ~DataBin( );
private:
   int* datum;
};
#endif /* DATABIN_H_ */
