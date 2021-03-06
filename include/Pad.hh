#ifndef _Pad_hh_
#define _Pad_hh_
#include <vector>
#include <math.h>
using std::vector;

namespace MyCalorimeter{
class Pad
{
	public:
	//
	//	Constants
	//
		static const int xNeigboursNumber = 3;
		static const int yNeigboursNumber = 3;
		static const int zNeigboursNumber = 3;
		static const float X1;
		static const float X2;
		
	//	static const float xSize = 10.0;
	//	static const float ySize = 10.0;
	//	static const float zSize = 10.0;
	//
	//	Constructors and destructor
	//
		Pad (int x, int y, int z);
		
		Pad (int x, int y, int z, vector<float> * sizes);
		
		virtual ~Pad ();
	//
	//	Operators
	//
		bool operator==(const Pad& another);
	//
	//	Methods
	//
		const vector<int> & GetCoordinates() const; 
		const vector<float> & GetRealCoordinates() const; 
		void SetRealCoordinates(float x, float y, float z);
		float GetEnergy() const;
		void SetEnergy(float someEnergy);
		void Dim();
		void SetIsShowerPad(bool value);
		vector<vector<vector<Pad*> > > * GetNeighbours();
		bool IsActive() const;
		void AddNeighbours(vector<vector<vector<Pad*> > > * array );
	private:
	//
	//	Members
	//
		vector<int> myCoordinates;
		vector<float> myRealCoordinates;
		vector<float> * myDimensions;
		float myEnergy;
		bool isShowerPad;
		vector<vector<vector<Pad*> > > * myNeighbours;
	//
	//	Private methods
	//
	protected:
	//
	//	Members
	//

};
}
#endif











