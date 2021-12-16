#ifndef __LEGENDRE__
#define __LEGENDRE__
class Legendre{
    private:
        typedef unsigned int uint;
    private:
        double alpha_;
        uint n_;
    public:
        Legendre(){
            alpha_=2.0;
            n_=0;
        }
        Legendre(double a, uint n){
            alpha_=a;
            n_=n;
        }
        
        void set_alpha(double a){
            alpha_=a;
        }
        void set_n(uint n){
            n_=n;
        }
        void set(double a, uint n){
            alpha_=a;
            n_=n;
        }
        double get_P(double x){
            if (n_<0) return d_cast(0);
            x*=d_cast(2)/alpha_;
            switch (n_){
                case 0: return P0(x);
                case 1: return P1(x);
                case 2: return P2(x);
                default: return Pn(x);
            }
        }
        double get_DP(double x){
            if (n_<=1) return d_cast(0);
            x*=d_cast(2)/alpha_;
            switch (n_){
                case 2: return d_cast(2)*x;
                default: return DPn(x);
            }
        }
    private:
        double d_cast(uint input){
            return static_cast<double>(input);
        }
        double P0(double x){
            return 1.0;
        }
        double P1(double x){
            return x;
        }
        double P2(double x){
            return (d_cast(3)*x*x-d_cast(1))/d_cast(2);
        }
        double Pn(double x){
            double pn_prev=P2(x);
            double pn_prev_prev=P1(x);
            double pn;
            for (auto m = 3u ; m <= n_ ; ++m){ 
                pn = (d_cast((2 * m) - 1) * x * pn_prev - (d_cast(m - 1) * pn_prev_prev)) / d_cast(m);
                pn_prev_prev = pn_prev;
                pn_prev = pn;
            }
            return pn;
        }
        double DPn(double x){
            double pn_prev=P2(x);
            double pn_prev_prev=P1(x);
            double pn;
            for (auto m = 3u ; m <= n_ ; ++m){ 
                pn = (d_cast((2 * m) - 1) * x * pn_prev - (d_cast(m - 1) * pn_prev_prev)) / d_cast(m);
                pn_prev_prev = pn_prev;
                pn_prev = pn;
            }
            return (x*pn-pn_prev_prev)*d_cast(n_)/(x*x-d_cast(1));
        }
};
#endif