bool isPowerOfBase(int n, int a) {
    if (n <= 0 || a <= 1) return false;
    double logResult = log(n) / log(a);
    return ceil(logResult) == floor(logResult);
}

bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}

bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}

vector<bool> sieve(int n){
    vector<bool>primes(n+1,true);

    primes[0]=false;
    primes[1]=false;

    for(int i=2;i<=sqrt(n);i++){
        if(primes[i]==true){
            // all multiples false
            for(int j=i*i;j<=n;j+=i){
                primes[j]=false;
            }
        }
    }

    return primes;
}

// #Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;
