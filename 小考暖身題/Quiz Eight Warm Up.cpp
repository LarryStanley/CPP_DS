#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>

using namespace std ;

class Polynomial {
  private :
    vector<double>  coeffs ;
    int  deg ;
  public :
    Polynomial( int s , double val )
        : coeffs(s,val) , deg(s-1) {}

    Polynomial( const vector<double>& cs )
        : coeffs(cs) , deg(cs.size()-1) {}

    double& operator[] ( int i ) { return coeffs[i] ; }
    const double& operator[] ( int i ) const { return coeffs[i] ; }
	double& operator() ( int value ){
		double *answer = new double;
		*answer = 0;
		for (int i = 0; i < coeffs.size(); i++)
			*answer = *answer + coeffs[i] * pow(value, i); 
		return *answer;
	}
    Polynomial derivative() const {
        vector<double>  cs(deg) ;
                for ( int i = 0 ; i < cs.size() ; ++i ) {
            cs[i] = coeffs[i+1]*(i+1) ;
        }
        return Polynomial(cs) ;
    }

	Polynomial derivative(int value) const {
		Polynomial p(coeffs);
		for (int i = 0 ; i < value; i ++)
			p = p.derivative();
        return p ;
    }

    friend ostream& operator<< ( ostream& out ,
                                 const Polynomial& foo ) {
        for ( int i = 0 ; i < foo.coeffs.size() ; ++i ) {
            if ( foo[i] != 0 ) {
                out << ( foo[i] > 0 ? " + " : " - " )
                    << ( foo[i] > 0 ? foo[i] : -foo[i] ) ;

                if ( i ) {
                    out << " X" ;
                    if ( i > 1) out << "^" << i ;
                }
            }
        }
        return out ;
    }
};

int main() {
    Polynomial p(5,3) ;
    p[1] = -4 ;
    p[3] = -5 ;
    cout << p << endl ;
	cout << p(3) << endl;
	cout << p.derivative() << endl;
    cout << p.derivative(2) << endl ;
	cout << p.derivative(2)(3) << endl;
    return 0 ;
}
