Below is a comprehensive, beginner‐friendly walkthrough of all the modular‐arithmetic and number‐theory ingredients you’ll need to get started in competitive programming (e.g. Codeforces). We’ve broken it into bite-sized sections, given plenty of small numeric examples, sketched out “how” and “why” things work, and finally pointed you toward a few starter Codeforces problems and practice‐strategies.

---

## 1. What Does “Modulo n” Mean?

Whenever we write

a   mod   n ,a \;\bmod\; n\,,
we mean “the remainder when aa is divided by nn.” Equivalently, we say

a≡b  ( mod   n)⟺n  ∣  (a−b),a \equiv b \;(\bmod\;n)
\quad\Longleftrightarrow\quad
n \;\Big|\;(a - b),
i.e. aa and bb leave the same remainder upon division by nn.

**Key fact:**

> If a≡r(modn)a \equiv r\pmod{n}, then rr is an integer in the range 0≤r<n0 \le r < n.

In CP, we almost always keep every intermediate result inside the range {0,1,2,…,n−1}\{0,1,2,\dots,n-1\}, so that our numbers never “blow up” beyond machine limits.

---

## 2. Addition, Subtraction, Multiplication “Mod n”

In a contest, you’ll often see the phrase “compute the answer mod nn.”  Concretely:

1. **Addition modulo nn.**

   (a+b) mod n  =  ( (a mod n)+(b mod n)) mod n.  (a + b)\bmod n
   \;=\; \bigl(\,(a \bmod n) + (b \bmod n)\bigr)\bmod n.

   * Example: Let n=7n=7, a=10a=10, b=12b=12.

     a mod 7=10 mod 7=3,b mod 7=12 mod 7=5,  a \bmod 7 = 10 \bmod 7 = 3,\quad
     b \bmod 7 = 12 \bmod 7 = 5,
     so

     (10+12) mod 7=22 mod 7=1,  (10 + 12)\bmod 7
     = 22 \bmod 7
     = 1,
     and also

     (3+5) mod 7=8 mod 7=1.  (3 + 5)\bmod 7 = 8 \bmod 7 = 1.
2. **Subtraction modulo nn.**

   (a−b) mod n  =  ( (a mod n)−(b mod n)) mod n.  (a - b)\bmod n
   \;=\; \bigl(\,(a \bmod n) - (b \bmod n)\bigr)\bmod n.
   In practice, implement it carefully to stay non‐negative:

   ```cpp
   int sub = ( (a % n) - (b % n) + n ) % n;  
   ```

   * Example: n=7,  a=10,  b=12n=7,\;a=10,\;b=12.

     10 mod 7=3,12 mod 7=5,(3−5) mod 7=−2 mod 7=5.  10 \bmod 7 = 3,\quad 12 \bmod 7 = 5,\quad
     (3 - 5) \bmod 7 = -2 \bmod 7 = 5.
     And indeed (10−12)=−2(10 - 12) = -2, and −2 mod 7=5-2 \bmod 7 = 5.
3. **Multiplication modulo nn.**

   (a×b) mod n  =  ( (a mod n)×(b mod n)) mod n.  (a \times b)\bmod n
   \;=\; \bigl(\,(a \bmod n) \times (b \bmod n)\bigr)\bmod n.

   * Example: n=7,  a=10,  b=12:n=7,\;a=10,\;b=12:

     (10 mod 7)=3,(12 mod 7)=5,(3×5) mod 7=15 mod 7=1.  (10 \bmod 7) = 3,\quad (12 \bmod 7) = 5,\quad
     (3 \times 5)\bmod 7 = 15 \bmod 7 = 1.
     And indeed 10×12=120,  120 mod 7=1.10\times12=120,\;120\bmod7=1.

**Why it “works”:**

All these rules follow from the definition a≡a mod na \equiv a \bmod n.  If

a≡a′(modn),b≡b′(modn),a \equiv a' \pmod{n},
\quad b \equiv b' \pmod{n},
then

a+b  ≡  a′+b′(modn),a−b  ≡  a′−b′(modn),a⋅b  ≡  a′⋅b′(modn).a+b \;\equiv\; a' + b' \pmod{n},
\quad
a-b \;\equiv\; a' - b' \pmod{n},
\quad
a\cdot b \;\equiv\; a'\cdot b' \pmod{n}.
In code, you simply do each operation  mod  n\bmod\,n at every step.

---

## 3. Division “mod n” (Multiplicative Inverses)

In ordinary arithmetic, ab\dfrac a b means “the unique real/rational/integer result such that (ab)×b=a\bigl(\tfrac a b\bigr) \times b = a.”  In modular arithmetic, “division by xx” is *not* always defined in the same way.  Instead, we define:

> **“Divide by xx (mod nn)”** means “multiply by the unique integer x−1x^{-1} such that
>
> x×x−1  ≡  1(modn),x \times x^{-1} \;\equiv\; 1 \pmod{n},
> if such an inverse exists.”

Hence,

ax  ( mod  n)  :=  a×(x−1)  ( mod  n),  \frac{a}{x} \;(\bmod\,n)\; :=\; a \times \bigl(x^{-1}\bigr)\;(\bmod\,n),
provided that xx actually has an inverse mod nn.

### 3.1. When does an inverse exist?

* A number xx has a *multiplicative inverse* modulo nn if and only if gcd⁡(x, n)=1\gcd(x,\,n) = 1.
* In particular, if nn is prime and 1≤x<n1 \le x < n, then gcd⁡(x,n)=1\gcd(x,n)=1, so every nonzero residue xx has an inverse mod nn.

> **Key takeaway:** “Division mod nn” is only possible when xx and nn are coprime.
>
> ∃ x−1(modn)  ⟺  gcd⁡(x,n)=1.\exists\,x^{-1}\pmod{n}\;\Longleftrightarrow\;\gcd(x,n)=1.

---

## 4. Fermat’s Little Theorem (and Euler’s Generalization)

Two extremely important theorems tell us how to exponentiate “mod nn” and how to find inverses via exponents.

### 4.1. Fermat’s Little Theorem (FLT)

**Statement (prime case).**

> If pp is prime and aa is any integer  *not divisible by pp* , then
>
> a p−1  ≡  1(modp).a^{\,p-1}\;\equiv\;1 \pmod{p}.

In other words, for 1≤a<p1\le a < p,   a p−1 mod p=1.\;a^{\,p-1} \bmod p = 1.

**Immediate corollary (inverse via exponent):**

> Whenever pp is prime and gcd⁡(a,p)=1\gcd(a,p)=1, one gets
>
> a p−2  ≡  a−1(modp).a^{\,p-2}\;\equiv\;a^{-1} \pmod{p}.

Why?  Multiply both sides of a p−2≡a−1(modp)a^{\,p-2} \equiv a^{-1} \pmod p by aa.  You want a p−2×a=a p−1≡1(modp)a^{\,p-2} \times a = a^{\,p-1} \equiv 1 \pmod p.  But that is exactly FLT.  Hence

a p−1  ≡  1(modp)  ⟹  a p−2  ≡  a−1(modp).a^{\,p-1} \;\equiv\;1 \pmod p
\;\Longrightarrow\;
a^{\,p-2} \;\equiv\; a^{-1}\pmod p.
So when you need to divide by aa mod a prime pp, you just raise to the (p−2)(p-2) power.

### 4.2. Euler’s Totient Theorem (Generalization)

Denote by φ(n)\varphi(n) (Euler’s totient function) the number of positive integers

{ 1,2,…,n−1}\{\,1,2,\dots,n-1\} that are coprime to nn.  In symbols:

φ(n)  =  ∣{ k  :  1≤k<n, gcd⁡(k,n)=1}∣.\varphi(n) \;=\; \bigl|\{\,k \;:\; 1 \le k < n,\ \gcd(k,n)=1\}\bigr|.

* If nn is prime, φ(n)=n−1\varphi(n) = n-1.
* If n=p1e1 p2e2⋯prern = p_1^{e_1}\,p_2^{e_2}\cdots p_r^{e_r} (its prime factorization), then

  φ(n)  =  n  ∏i=1r(1−1pi).\varphi(n) \;=\; n\;\prod_{i=1}^r \Bigl(1 - \tfrac{1}{p_i}\Bigr).

**Euler’s Theorem.**

> If gcd⁡(a,n)=1\gcd(a,n)=1, then
>
> a φ(n)  ≡  1(modn).a^{\,\varphi(n)} \;\equiv\; 1 \pmod{n}.

In particular, whenever gcd⁡(a,n)=1\gcd(a,n)=1,

a φ(n)−1  ≡  a−1(modn).a^{\,\varphi(n)-1} \;\equiv\; a^{-1} \pmod{n}.
(Just multiply both sides of aφ(n)≡1a^{\varphi(n)} \equiv 1 by a−1a^{-1}.)

Because computing φ(n)\varphi(n) for a general nn requires factoring nn (which can be expensive for large nn), in CP we often rely on two special cases:

1. nn is prime ⇒\Rightarrow use FLT (φ(n)=n−1\varphi(n)=n-1).

2. nn is composite but “small enough” that factoring is okay (e.g.\ if n≤106n \le 10^6, you can sieve for primes and get φ(n)\varphi(n)).

---

## 5. The Euclidean Algorithm and the Extended Euclidean Algorithm

### 5.1. The (Standard) Euclidean Algorithm

This is the fastest way to compute gcd⁡(a,b)\gcd(a,b).  Recall:

gcd⁡(a,b)={gcd⁡(b, a mod b),b≠0,a,b=0.\gcd(a,b)
= \begin{cases}
\gcd(b,\,a \bmod b), & b \neq 0,\\
a, & b=0.
\end{cases}
In code (C++ style):

```cpp
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;  // now b==0, so a is gcd.
}
```

**Example:** gcd⁡(56, 15)\gcd(56,\,15).

* Step 1: 56 mod 15=1156 \bmod 15 = 11.  So gcd⁡(56,15)=gcd⁡(15,11)\gcd(56,15) = \gcd(15,11).
* Step 2: 15 mod 11=415 \bmod 11 = 4.  So gcd⁡(15,11)=gcd⁡(11,4)\gcd(15,11) = \gcd(11,4).
* Step 3: 11 mod 4=311 \bmod 4 = 3.  So gcd⁡(11,4)=gcd⁡(4,3)\gcd(11,4) = \gcd(4,3).
* Step 4: 4 mod 3=14 \bmod 3 = 1.  So gcd⁡(4,3)=gcd⁡(3,1)\gcd(4,3) = \gcd(3,1).
* Step 5: 3 mod 1=03 \bmod 1 = 0.  So gcd⁡(3,1)=1\gcd(3,1)=1.

Hence gcd⁡(56,15)=1\gcd(56,15)=1.

### 5.2. The Extended Euclidean Algorithm

This not only computes gcd⁡(a,b)\gcd(a,b) but also finds integers x,yx,y such that

a x  +  b y  =  gcd⁡(a,b).a\,x \;+\; b\,y \;=\; \gcd(a,b).
In particular, if gcd⁡(a,n)=1\gcd(a,n)=1, the Extended Euclid will produce x,yx,y so that

a x+n y=1    ⟹    a x≡1(modn).a\,x + n\,y = 1
\;\;\Longrightarrow\;\; a\,x \equiv 1 \pmod{n}.
Thus xx is the multiplicative inverse of aa mod nn.

A standard recursive implementation:

```cpp
// returns gcd(a,b), and populates x, y so that a*x + b*y = gcd(a,b)
long long ext_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;  // gcd(a,0) = a
    }
    long long x1, y1;
    long long g = ext_gcd(b, a % b, x1, y1);
    // Now x1, y1 satisfy: b*x1 + (a % b)*y1 = g.
    // But a % b = a - (a/b)*b, so:
    //   b*x1 + (a - (a/b)*b)*y1 = g
    //   a*y1 + b*( x1 - (a/b)*y1 ) = g
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
```

**Example (find inverse of aa mod nn when gcd⁡(a,n)=1\gcd(a,n)=1).**

Let’s invert a=10a=10 modulo n=21n=21.  Since gcd⁡(10,21)=1\gcd(10,21)=1, there is an inverse. Call `ext_gcd(10,21,x,y)`.

1. We do `ext_gcd(21, 10)`, then keep recursing… eventually we find

   gcd⁡(10, 21)=1, x=−2,  y=1.\gcd(10,\,21) = 1,x = -2,\; y = 1.
   That is,

   10×(−2)+21×1=−20+21=1.10 \times (-2) + 21 \times 1 = -20 + 21 = 1.
2. From 10⋅(−2)≡1(mod21)10 \cdot (-2) \equiv 1 \pmod{21}, we see that −2-2 is an inverse of 1010.  Usually we want a residue in [0,20][0,20], so

   x=−2≡19(mod21).x = -2 \equiv 19 \pmod{21}.
   Check: 10×19=190≡1(mod21)10 \times 19 = 190\equiv 1\pmod{21}.

Therefore, 10−1 mod 21=1910^{-1} \bmod{21} = 19.

---

## 6. “How to Find the Inverse of x(modn)x\pmod n”

1. **If nn is prime (say n=pn=p)**

   – Check gcd⁡(x,p)\gcd(x,p).  If gcd⁡(x,p)=1\gcd(x,p)=1 (i.e.\ x≢0(modp)x\not\equiv 0\pmod p), then by FLT:

   x p−2   mod  p  =  x−1(modp).x^{\,p-2} \;\bmod\,p
   \;=\; x^{-1} \pmod{p}.
   – Implementation: do a fast exponentiation of xx to the exponent p−2p-2 modulo pp.  (Cost: O(log⁡p)O(\log p).)
2. **If nn is composite (or you don’t want to rely on FLT)**

   – Compute gcd⁡(x,n)\gcd(x,n).  If it is ≠1\neq 1, then there is no inverse.  If gcd⁡(x,n)=1\gcd(x,n)=1, run the Extended Euclidean Algorithm to produce coefficients (u,v)(u,v) satisfying

   x u+n v=1    ⟹    x u≡1(modn).x\,u + n\,v = 1
   \;\;\Longrightarrow\;\; x\,u \equiv 1 \pmod{n}.
   – Then u mod nu \bmod n is the multiplicative inverse of xx.

### 6.1. Fast Exponentiation (“Binary Exponentiation” / “Modular Power”)

Whenever you see xk mod mx^k \bmod m with kk up to, say, 10910^9 or larger, you cannot loop kk times.  Instead, you do “binary exponentiation.”

```cpp
// compute (base^exp) % mod in O(log exp) time
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) 
            result = ( (result % mod) * (base % mod) ) % mod;
        base = ( (base % mod) * (base % mod) ) % mod;
        exp >>= 1;  // divide exp by 2
    }
    return result;
}
```

* Example (prime case): Let p=13p=13, x=5x=5.  Then

  **5^{11} \bmod 13
  = \text{modPow}(5,\,11,\,13) = 8
  \]\
  indeed \(5^{11} = 48{,}828{,}125\equiv 8\pmod{13}\).  Check FLT: \(5^{12}\bmod13=1\).  **

---

## 7. Putting It All Together: Division in a Nutshell

* **When you see a division “/ x/\,x” inside a  mod n\bmod n problem: replace it by “× x−1\times\,x^{-1}”** , provided gcd⁡(x,n)=1\gcd(x,n)=1.
* **If nn is prime** : compute x−1≡x n−2 mod nx^{-1} \equiv x^{\,n-2}\bmod n via fast exponentiation.
* **Otherwise** : run ext_gcd(x,n)\mathrm{ext\_gcd}(x,n) to compute an integer uu with x u+n v=1x\,u + n\,v = 1.  Then u mod nu \bmod n is x−1x^{-1}.

**Numeric mini‐example (division mod prime):**

> Compute 73 mod 11\tfrac{7}{3} \bmod 11.
>
> 1. gcd⁡(3,11)=1\gcd(3,11)=1.  Since 11 is prime,
>
>    3−1 mod 11  =  3 11−2 mod 11=39 mod 11.3^{-1} \bmod 11 \;=\; 3^{\,11-2} \bmod 11
>    = 3^9 \bmod 11.
> 2. Compute 39 mod 113^9 \bmod 11.  Fast exponentiation gives 39≡4(mod11)3^9 \equiv 4\pmod{11} (you can check: 35=243≡13^5=243\equiv1, 39=35⋅34≡1⋅(32)2=92=81≡43^9 = 3^5\cdot3^4\equiv 1\cdot(3^2)^2=9^2=81\equiv4).
> 3. So 73 mod 11=7×3−1 mod 11=7×4 mod 11=28 mod 11=6.\tfrac{7}{3} \bmod 11 = 7\times 3^{-1} \bmod 11 = 7\times 4 \bmod 11 = 28 \bmod 11 = 6.

**Numeric mini‐example (division mod composite):**

> Compute 73 mod 10\tfrac{7}{3} \bmod 10.
>
> 1. Check gcd⁡(3,10)=1\gcd(3,10)=1, so inverse exists.
> 2. Run Extended Euclid on (3,10)(3,10).  We find x,yx,y such that 3x+10y=13x + 10y = 1.  A quick run:
>    * 10=3⋅3+110 = 3\cdot 3 + 1, so 1=10−3⋅31 = 10 - 3\cdot 3.
>    * Meanwhile 3=3⋅1+03 = 3\cdot 1 + 0.
>    * Back‐substitute: 1=10−3⋅31 = 10 - 3\cdot 3.  But 3=3⋅13 = 3\cdot 1.  So we see 1=10−3⋅31 = 10 - 3\cdot 3.  In other words, x=−3,  y=1x = -3,\; y=1.
> 3. Therefore 3−1 mod 10≡−3 mod 10≡73^{-1} \bmod 10 \equiv -3 \bmod 10 \equiv 7 .  Check: 3×7=21≡1(mod10).3\times7=21\equiv1\pmod{10}.
> 4. Finally 73 mod 10=7×7 mod 10=49 mod 10=9.\tfrac{7}{3} \bmod 10 = 7 \times 7 \bmod 10=49\bmod 10=9.

---

## 8. Chinese Remainder Theorem (CRT)

Suppose you have two (or more) simultaneous congruences:

{x  ≡  a(modn),x  ≡  b(modm),\begin{cases}
x \;\equiv\; a \pmod{n},\\
x \;\equiv\; b \pmod{m},
\end{cases}
with gcd⁡(n,m)=1\gcd(n,m)=1.  CRT guarantees that there is a unique solution

 x\,x modulo N=n mN = n\,m.

### 8.1. Constructive recipe (two moduli)

1. Compute N=n⋅mN = n\cdot m.
2. Let N1=N/n=mN_1 = N / n = m, and N2=N/m=nN_2 = N / m = n.
3. Find inverses:

   * y1:=(N1)−1 mod ny_1 := (N_1)^{-1} \bmod n.
   * y2:=(N2)−1 mod my_2 := (N_2)^{-1} \bmod m.

     (Because gcd⁡(N1,n)=1\gcd(N_1,n)=1 and gcd⁡(N2,m)=1\gcd(N_2,m)=1.)
4. Then one solution is

   x  =  a⋅(N1 y1)  +  b⋅(N2 y2)   mod   N.x \;=\; a\cdot (N_1\,y_1) \;+\; b\cdot (N_2\,y_2)
   \;\bmod\;N.
   Equivalently,

   x  =  (a×m×(m−1 mod n))+(b×n×(n−1 mod m))(mod nm ).x \;=\; \bigl(a \times m \times (m^{-1}\bmod n)\bigr)
   + \bigl(b \times n \times (n^{-1}\bmod m)\bigr)
   \pmod{\,nm\,}.

**Example:**

Solve

x≡2(mod5),x≡3(mod7).x \equiv 2 \pmod{5},
\qquad
x \equiv 3 \pmod{7}.

* Here n=5,  m=7,  N=35.n=5,\;m=7,\;N=35.
* N1=7,  N2=5.N_1 = 7,\;N_2 = 5.
* Inverse: 7−1 mod 57^{-1} \bmod 5.  Since  7≡2(mod5)\,7 \equiv 2\pmod5, we want 2 y1≡1(mod5)2\,y_1 \equiv 1\pmod5.  That gives y1=3y_1=3, because 2⋅3=6≡12\cdot3=6\equiv1.
* Next: 5−1 mod 75^{-1}\bmod7.  Since 5≡5(mod7)5\equiv5\pmod7, solve 5 y2≡1(mod7)5\,y_2\equiv1\pmod7.  Try y2=3y_2=3: 5⋅3=15≡1(mod7)5\cdot3=15\equiv1\pmod7.  So y2=3y_2=3.
* Now assemble:

  x=2⋅(7×3)  +  3⋅(5×3)  =  2⋅21+3⋅15  =  42+45=87(mod35).x
  = 2 \cdot (7 \times 3)
  \;+\; 3 \cdot (5 \times 3)
  \;=\; 2\cdot21 + 3\cdot15
  \;=\; 42 + 45 = 87
  \pmod{35}.
* Finally 87 mod 35=87−2⋅35=17.87 \bmod 35 = 87 - 2\cdot35 = 17.  So x≡17(mod35)x\equiv17\pmod{35}.
* Check: 17 mod 5=217 \bmod 5 = 2, 17 mod 7=317 \bmod 7 = 3.

### 8.2. More than two moduli

Just repeat pairwise or use the general “Ni, yiN_i,\,y_i” construction for each modulus.  As long as all moduli are pairwise coprime, there is exactly one solution mod the product of all moduli.

---

## 9. Some Simple Examples (Step by Step)

### Example 1: Direct arithmetic mod a prime

> **Problem:** Compute ( 175+237)/  19 mod 19.\Bigl(\,17^5 + 23^7\Bigr)\bigl/\;19 \bmod 19.
>
> 1. We want (175+237)×(19−1) mod 19.\bigl(17^5 + 23^7\bigr)\times (19^{-1}) \bmod 19.
> 2. Because 1919 is prime, 19−1 mod 19=19 17 mod 1919^{-1} \bmod 19 = 19^{\,17} \bmod 19.  But 19≡0(mod19)19 \equiv 0 \pmod{19}, so directly using that is silly—any multiple of 19 is 0 mod 19.  Actually, the problem is trivial: dividing by 19 mod 19 forces everything to be “is it divisible by 19?” If ( 175+237)(\,17^5 + 23^7) is not divisible by 19, then there is no inverse.
> 3. More likely the intended problem was “Compute (175+237) mod 19\bigl(17^5 + 23^7 \bigr)\bmod 19.”  In that case, do:
>    * 17 mod 19=1717 \bmod 19 = 17.  Compute 175 mod 1917^5 \bmod 19 by fast power.
>
>      172 mod 19=289 mod 19=4,174 mod 19=42=16,175 mod 19=16×17 mod 19=272 mod 19=6.17^2 \bmod 19 = 289 \bmod 19 = 4,
>      \quad
>      17^4 \bmod 19 = 4^2 = 16,
>      \quad
>      17^5 \bmod 19 = 16\times 17 \bmod 19 = 272 \bmod 19 = 6.
>    * 23 mod 19=423 \bmod 19 = 4.  Then 47 mod 194^7 \bmod 19:
>
>      42=16,  44=162=256 mod 19=9,  47=44⋅42⋅41=9⋅16⋅4=576 mod 19=576−30⋅19=576−570=6.4^2 = 16,\;4^4 = 16^2 = 256 \bmod 19 = 9,\;
>      4^7 = 4^4\cdot4^2\cdot4^1 = 9\cdot16\cdot4 = 576 \bmod 19 = 576 - 30\cdot19 = 576 - 570 = 6.
>    * So 175+237 mod 19=(6+6) mod 19=12.17^5 + 23^7 \bmod 19 = (6 + 6)\bmod19 = 12.

### Example 2: Using Fermat’s Little Theorem to invert

> **Problem:** Find xx such that 3 x≡5(mod11)3\,x \equiv 5 \pmod{11}.
>
> 1. Since 11 is prime, 3−1 mod 11=3 9 mod 113^{-1} \bmod 11 = 3^{\,9} \bmod 11.
> 2. Compute 39 mod 113^9 \bmod 11:
>    * 32=93^2=9.
>    * 34=92=81 mod 11=4.3^4 = 9^2 = 81 \bmod 11 = 4.
>    * 38=42=16 mod 11=5.3^8 = 4^2 = 16 \bmod 11 = 5.
>    * 39=38⋅3=5×3=15 mod 11=4.3^9 = 3^8 \cdot 3 = 5 \times 3 = 15 \bmod 11 = 4.
> 3. Therefore 3−1≡4(mod11)3^{-1} \equiv 4 \pmod{11} (check: 3×4=12≡13 \times 4 =12\equiv1).
> 4. So x≡5×3−1 mod 11=5×4 mod 11=20 mod 11=9.x \equiv 5 \times 3^{-1} \bmod 11 = 5 \times 4 \bmod 11 =20 \bmod 11 = 9.

### Example 3: Using Extended Euclid to invert (composite case)

> **Problem:** Solve 7 x≡1(mod26).7\,x \equiv 1 \pmod{26}.  (Here gcd⁡(7,26)=1\gcd(7,26)=1.)
>
> 1. Run Extended Euclid on (7,26)(7,26):
>
>    * 26=7⋅3+526 = 7\cdot3 + 5.
>    * 7=5⋅1+27 = 5\cdot1 + 2.
>    * 5=2⋅2+15 = 2\cdot2 + 1.
>    * 2=1⋅2+02 = 1\cdot2 + 0.
>
>      So gcd⁡(7,26)=1.\gcd(7,26)=1.  Back-substitute:
>
>    1=5−2⋅2,2=7−5⋅1,5=26−7⋅3.1 = 5 - 2\cdot2,\quad
>    2 = 7 - 5\cdot1,
>    \quad
>    5 = 26 - 7\cdot3.
>    Then
>
>    1=5−2⋅2=5−2⋅(7−5⋅1)=5⋅3−7⋅2=(26−7⋅3)⋅3−7⋅2=26⋅3−7⋅(9+2)=26⋅3−7⋅11.1 = 5 - 2\cdot2
>    = 5 - 2\cdot(7-5\cdot1)
>    = 5\cdot3 - 7\cdot2
>    = (26 - 7\cdot3)\cdot3 - 7\cdot2
>    = 26\cdot3 - 7\cdot(9+2)
>    = 26\cdot3 - 7\cdot11.
>    So we read off: x=−11,  y=3x = -11,\;y = 3.  (Because 7 (−11)+26 (3)=17\,(-11) + 26\,(3) = 1.)
> 2. Therefore 7−1≡−11 mod 26≡15.7^{-1} \equiv -11 \bmod 26 \equiv 15.  Check: 7×15=105≡1(mod26).7\times15=105\equiv1\pmod{26}.

---

## 10. Putting CRT to Work: A Small Example

> **Problem:** Find the smallest nonnegative integer xx such that
>
> x≡1(mod4),x≡2(mod5),x≡3(mod7).x \equiv 1 \pmod{4},
> \qquad
> x \equiv 2 \pmod{5},
> \qquad
> x \equiv 3 \pmod{7}.

1. All moduli 4,5,74,5,7 are pairwise coprime.  Let N=4⋅5⋅7=140N = 4\cdot5\cdot7 = 140.
2. For each modulus nin_i, set Ni=N/niN_i = N / n_i:

   * N1=140/4=35N_1 = 140/4 = 35.
   * N2=140/5=28N_2 = 140/5 = 28.
   * N3=140/7=20N_3 = 140/7 = 20.
3. Compute inverses:

   * y1=35−1 mod 4y_1 = 35^{-1} \bmod 4.  Since 35≡3(mod4),  3 y1≡1(mod4)35 \equiv 3\pmod4,\;3\,y_1\equiv1\pmod4, so y1=3y_1=3 (because 3⋅3=9≡1(mod4)3\cdot3=9\equiv1\pmod4).
   * y2=28−1 mod 5y_2 = 28^{-1} \bmod 5.  Since 28≡3(mod5),  3 y2≡1(mod5)28\equiv3\pmod5,\;3\,y_2\equiv1\pmod5, so y2=2y_2=2 (because 3⋅2=6≡1(mod5)3\cdot2=6\equiv1\pmod5).
   * y3=20−1 mod 7y_3 = 20^{-1} \bmod 7.  Since 20≡6(mod7),  6 y3≡1(mod7)20\equiv6\pmod7,\;6\,y_3\equiv1\pmod7, so y3=6y_3=6 (because 6⋅6=36≡1(mod7)6\cdot6=36\equiv1\pmod7).
4. Combine:

   x=( 1⋅35⋅3)  +  (2⋅28⋅2)  +  (3⋅20⋅6)   mod  140.x = (\,1\cdot 35\cdot 3)\;+\;(2\cdot28\cdot2)\;+\;(3\cdot20\cdot6)\;\bmod\,140.

   * 1⋅35⋅3=1051\cdot35\cdot3 = 105.
   * 2⋅28⋅2=1122\cdot28\cdot2 = 112.
   * 3⋅20⋅6=3603\cdot20\cdot6 = 360.

     Summing: 105+112+360=577.105 + 112 + 360 = 577.

     577 mod 140=577−4⋅140=577−560=17.577 \bmod 140 = 577 - 4\cdot140 = 577 - 560 = 17.

     So x=17x=17.  Check:

   17 mod 4=1,17 mod 5=2,17 mod 7=3.17 \bmod 4 = 1,\quad
   17 \bmod 5 = 2,\quad
   17 \bmod 7 = 3.

---

## 11. Common Pitfalls & Strategies in Codeforces‐Style “Mod 109+710^9+7” Problems

Most Codeforces (and AtCoder, etc.) problems that ask “print your answer mod 109+710^9+7” want you to:

1. Keep **all** additions, subtractions, multiplications, and exponentiations inside  mod  109+7\bmod\,10^9+7.
2. Avoid overflow (use 64-bit integers, e.g.\ `long long` in C++).
3. Have a reusable template for:
   * `add(a,b,mod)`, `sub(a,b,mod)`, `mul(a,b,mod)`,
   * `modPow(a,exp,mod)`,
   * `inv(a,mod)` when `gcd(a,mod)==1`.
4. Watch out for negative remainders.  Always do `((x % MOD) + MOD) % MOD` when subtracting.

### 11.1. A Typical C++ Template Snippet

```cpp
const int MOD = 1'000'000'007;

// safe addition
int add(int a, int b) {
    int s = a + b;
    if (s >= MOD) s -= MOD;
    return s;
}

// safe subtraction
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += MOD;
    return s;
}

// safe multiplication (if a,b < MOD, then (long long)a*b < (MOD^2) fits in 64 bits)
int mul(int a, int b) {
    return int((long long)a * b % MOD);
}

// binary exponentiation
long long modPow(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

// inverse when MOD is prime: a^(MOD-2) % MOD
int inv(int a) {
    // assumes 1 <= a < MOD and gcd(a,MOD)=1
    return int(modPow(a, MOD-2));
}
```

### 11.2. When to Use Extended GCD Instead of FLT?

* If nn is the special prime 109+710^9+7 or 998244353998244353, you simply do `inv(a) = modPow(a, n-2)`.
* If the modulus is not prime (e.g.\ n=109+9n=10^9+9 or some composite), do not use exponent (n−2)(n-2).  Instead, run `ext_gcd(a,n)` to find the inverse (if gcd⁡(a,n)=1\gcd(a,n)=1).

### 11.3. Watch Out for Overflows in “a×ba \times b”

If a,ba,b can be up to 109+610^9+6, then a×ba\times b can be ≈1018\approx 10^{18}, which still fits in a signed 64-bit `long long`, but you must cast properly:

```cpp
long long prod = (long long)a * b;
int c = int(prod % MOD);
```

Alternatively use a built-in 128-bit type (e.g.\ `__int128`) if needed.

---

## 12. Chinese Remainder Theorem: When & Why?

CRT becomes handy when the problem asks for a number xx satisfying two or more modular constraints (e.g.\ “Find the smallest nonnegative xx such that x mod 4=3x \bmod 4 = 3 and x mod 9=5x \bmod 9 = 5 and x mod 11=7x \bmod 11 = 7.”).  Rather than brute-force check up to the product 4⋅9⋅11=3964\cdot9\cdot11=396, you use the constructive algorithm (for each modulus: compute its partial product ×\times inverse, sum up, then  mod \bmod the big product).

In CF, you’ll occasionally see “Chinese Remainder” in tags.  Usually you only need to handle two or three equations, and all moduli are guaranteed pairwise coprime.

---

## 13. “Phi” Function: Definition and Why We Don’t Compute It in Every Problem

> φ(n)\displaystyle \varphi(n) = number of integers in {1,2,…,n−1}\{1,2,\dots,n-1\} that are coprime to nn.

If you needed Euler’s theorem for a *composite* modulus nn, you would have to factor nn in order to compute φ(n)\varphi(n).  Factoring can be expensive if nn is large prime times prime, etc.  In a contest, either:

1. **They give you nn by its prime factorization** , so you can get φ(n)\varphi(n) easily.
2. **They guarantee nn is prime** , so you just set φ(n)=n−1\varphi(n)=n-1.

Unless you enjoy implementing a fast sieve or prime-factor routine, it’s best to focus on the **prime‐modulus** case and extended GCD case.  Once you see the theorem, the statement is:

> **Euler’s Theorem (general):** If gcd⁡(a,n)=1\gcd(a,n)=1, then
>
> a φ(n)≡1    ( mod  n).a^{\,\varphi(n)} \equiv 1 \;\;(\bmod\,n).

---

## 14. Putting It All in One Place: Quick “Flashcards”

1. **Modular Definition**

   * a≡b(modn)a \equiv b \pmod{n}   ⟺  \iff n∣(a−b)n \mid (a-b).
   * Always reduce intermediate results into [0,…,n−1][0,\dots,n-1].
2. **Basic Operations**

   * (a+b) mod n=((a mod n)+(b mod n)) mod n(a + b)\bmod n = \bigl( (a\bmod n) + (b\bmod n) \bigr)\bmod n.
   * (a−b) mod n=((a mod n)−(b mod n)+n) mod n(a - b)\bmod n = \bigl( (a\bmod n) - (b\bmod n) + n \bigr)\bmod n.
   * (a×b) mod n=((a mod n)×(b mod n)) mod n(a \times b)\bmod n = \bigl( (a\bmod n)\times (b\bmod n) \bigr)\bmod n.
3. **Multiplicative Inverse**

   * xx has an inverse mod nn iff gcd⁡(x,n)=1\gcd(x,n)=1.
   * If nn is prime: x−1≡x n−2 mod nx^{-1} \equiv x^{\,n-2} \bmod n.
   * If nn is composite: use Extended Euclidean to find uu so that x u+n v=1x\,u + n\,v = 1; then u mod nu \bmod n is x−1x^{-1}.
4. **Fermat’s Little Theorem** (prime pp):

   a p−1≡1(modp),⟹a p−2≡a−1(modp).a^{\,p-1} \equiv 1 \pmod{p},
   \quad
   \Longrightarrow\quad
   a^{\,p-2} \equiv a^{-1} \pmod{p}.
5. **Euler’s Theorem** (general nn):

   a φ(n)≡1(modn)(gcd⁡(a,n)=1),⟹a φ(n)−1≡a−1(modn).a^{\,\varphi(n)} \equiv 1 \pmod{n}\quad
   \bigl(\gcd(a,n)=1\bigr),
   \quad\Longrightarrow\quad
   a^{\,\varphi(n)-1} \equiv a^{-1} \pmod{n}.
6. **Euclidean Algorithm** (`gcd(a,b)`) runs in O(log⁡min⁡(a,b))O(\log\min(a,b)).
7. **Extended GCD** (`ext_gcd(a,b,x,y)`) also in O(log⁡min⁡(a,b))O(\log\min(a,b)), returns gcd⁡(a,b)\gcd(a,b) plus integers x,yx,y such that a x+b y=gcd⁡(a,b)a\,x + b\,y = \gcd(a,b).
8. **Chinese Remainder Theorem (CRT)**

   * If gcd⁡(ni,nj)=1\gcd(n_i,n_j)=1 for all i≠ji\neq j, then the system x≡ai(modni)x \equiv a_i \pmod{n_i} has exactly one solution mod N=∏iniN=\prod_i n_i.
   * Construct it by weighting each aia_i with the product of all other moduli times the inverse.

---

## 15. Starter Codeforces Problems (Difficulty: 800–1200)

Below are a handful of very‐basic Codeforces problems to help you practice modular arithmetic, inverses, and CRT.  Start at the lower ratings (800–1000) and work your way up.  As you solve them, pay attention to the tags: look for  **“math”** ,  **“number theory”** ,  **“modular arithmetic”** , and  **“crt”** .  If you get stuck, read the editorial closely—most Editorias will explicitly point out “use modular inverse” or “apply CRT.”

1. **1485A – Add and Divide**  (≈ 900 rating)
   * You are given two integers a,ba,b.  You may repeatedly add 11 to aa, then once you decide to stop, you must divide the new aa by bb.  Minimize the total number of “+1” operations plus “divide once.”
   * Why it’s useful: you’ll check “while (a mod b)≠0(a \bmod b) \neq 0, do a++a++” to make aa divisible by bb, then do “a/ba/b.”
   * Tags: math, greedy, implementation.
2. **1101A – Minimum Integer**  (≈ 900 rating)
   * Given nn and digit sum limit ss, find the smallest integer x≥nx \ge n whose digits sum to at most ss.
   * Why it’s useful: you often need to do “(n mod 10),(n mod 100),(n mod 1000),…(n \bmod 10), (n\bmod 100), (n\bmod 1000),\dots” to tweak the last few digits.
3. **1343C – Alternating Subsequence**  (≈ 900 rating)
   * Not purely modular, but you practice taking partial sums and ensuring  mod 2\bmod 2 constraints.
4. **1629A – Download More RAM**  (≈ 900 rating)
   * “If xx is a multiple of yy, print 0; otherwise, print min⁡( (x mod y),  y−(x mod y))\min(\,(x \bmod y),\;y-(x \bmod y)\bigl).”  Straightforward “mod” practice.
5. **1110B – Tape**  (≈ 1000 rating)
   * You need to check positions modulo some number (circular‐array style).
6. **1462A – Favorite Sequence**  (≈ 1000 rating)
   * Just simple indexing, but you’ll often see “i mod ni \bmod n” to wrap around the circle.
7. **1602A – Two Subsequences**  (≈ 1200 rating)
   * Might involve constructing subsequences whose remainders match.
8. **1220B – Multiplication Table**  (≈ 1200 rating)
   * Given nn, count pairs (i,j)(i,j) with 1≤i,j≤n1 \le i,j \le n so that (i×j) mod 5=0(i\times j)\bmod 5 = 0.  You’ll practice counting how many residues are multiples of 5.
9. **1352C – K-th Not Divisible by n**  (≈ 1200 rating)
   * Find the kk-th positive integer that is *not* divisible by nn.  You’ll use ⌊x/n⌋\lfloor x / n\rfloor logic.
10. **1236B – Alice and the List of Presents** (≈ 1200 rating)
    * You look for consecutive runs—works with remainders if you interpret positions mod 26.

> **Tip:** On Codeforces, go to the Problemset, click the “Filters” button, check tags **“math”** or  **“number theory”** , and sort by difficulty.  Solve all the 800–1000 problems with those tags first.  As soon as you see a problem that says “Answer mod 109+710^9+7,” pause and make sure you have a modular‐arithmetic snippet ready.

---

## 16. “Beginner-to-Expert” Roadmap & Strategies (to reach Codeforces Expert by end 2025)

1. **Master the Basics (Next 2–3 months).**
   * **Implement a small template** for modular arithmetic (add, sub, mul, pow, inv via FLT).
   * **Solve every 800–1000 problem** with tags “math” or “number theory.”
   * **Time yourself.** The first few weeks, don’t worry about time—focus on correctness.  By the end of month 2, you should solve an 800-rated “modular” problem in 15-20 minutes.
2. **Build Your “Recipe-Book” of Tricks.**
   * Whenever you encounter a new “mod trick” or “number-theory trick” (e.g. “factoring a polynomial mod pp,” “exponent‐by‐squaring,” “Lucas’s theorem for binomial mod prime”), add it to a personal cheat sheet.
   * Practice a handful of  **prewritten code snippets** :
     * Fast I/O,
     * Binary exponentiation,
     * Extended Euclid,
     * Sieve + φ(n)\varphi(n) precomputation up to 10610^6.
3. **Start Competing in TL–CL (4–6 months).**
   * Join **Codeforces Div.~3** or **Div.~4** contests.  Even if you solve only one or two problems in 75 minutes, that’s okay.  Focus on “getting up to 1000 rating” by accumulating solves.
   * Read **every editorial** for problems you can’t solve in 20 minutes.  As you read, code up the solution on your own, line by line.
4. **Focus Permutations of Tags; Increase Difficulty (6–12 months).**
   * After you’ve comfortably solved 800–1000 with tags “math,” “number theory,” move to 1000–1400.  Keep adding “dp,” “greedy,” “two pointers,” “data structures” tags.
   * **Aim for a “solve‐time reduction.”**  If you solve a 1200 problem in 20 minutes today, re-attempt it in 15, then 10.  You want your “average solve time” for 1200 to be under 15 minutes by month 12.
5. **Learn to Read Others’ Code (9–15 months).**
   * After ~6 months of practice, pick **top competitors’ submissions** (e.g.\ tourist, Benq) for problems you solved.  Compare their code layout, macros, how they implement modPow, how they handle long long vs. int.  Incorporate what you like.
   * **Use a code template** : have `modAdd(a,b)`, `modMul(a,b)`, etc., so you don’t rewrite `%MOD` every time.
6. **Tackle More Number-Theory (12–18 months).**
   * Once you’re comfortable with modular inverses and CRT, start learning:
     * **Sieve + precompute φ(n)\varphi(n) up to 10610^6.**
     * **Prime‐factorization tricks** (trial division, Pollard’s rho if you want to go deeper).
     * **Combinatorics mod pp** : precompute factorials and inv-factorials to compute (nk) mod p\binom{n}{k}\bmod p.
   * Solve CF problems tagged **“combinatorics,” “fft,” “nt”** around 1500–1800 rating.
7. **Push Your Rating to “Master Levels” (18–24 months).**
   * By the time you’ve done ~200–300 problems and participated in ~30–40 contests, you should be nearing  **Expert (1900–2000 rating)** .
   * Keep practicing the unusual modular/number‐theory patterns:
     * “CRT + Exponent” problems
     * “Inverses + factorial + combinatorics”
     * “Matrix exponentiation mod 109+710^9+7.”
   * Once you can solve two ~1800-rated problems in a 2-hour session, you are effectively at **Expert** level.

---

## 17. Concrete Code Snippets You Will Reuse (C++ Style)

### 17.1. Modular Arithmetic Utility (Header)

```cpp
//========================
//  mod_arithmetic.h
//========================

#pragma once
#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1'000'000'007;

// safe addition
inline int add_mod(int a, int b) {
    int s = a + b;
    if (s >= MOD) s -= MOD;
    return s;
}

// safe subtraction
inline int sub_mod(int a, int b) {
    int s = a - b;
    if (s < 0) s += MOD;
    return s;
}

// safe multiplication
inline int mul_mod(long long a, long long b) {
    return int( (a % MOD) * (b % MOD) % MOD );
}

// binary exponentiation
long long mod_pow(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1LL) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1LL;
    }
    return result;
}

// inverse mod when MOD is prime
inline int inv_mod(int a) {
    // by Fermat: a^(MOD-2) mod MOD
    return int(mod_pow(a, MOD - 2));
}

// gcd (standard)
long long gcd(long long a, long long b) {
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// extended gcd: returns g=gcd(a,b) and finds x,y so that a*x + b*y = g
long long ext_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = ext_gcd(b, a % b, x1, y1);
    // back-substitution:
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// inverse mod for arbitrary n (only valid if gcd(a,n)=1)
long long inv_mod_ll(long long a, long long n) {
    long long x, y;
    long long g = ext_gcd(a, n, x, y);
    if (g != 1) return -1;  // no inverse
    x %= n;
    if (x < 0) x += n;
    return x;
}
```

### 17.2. Sample “Divide Two Numbers” Function

```cpp
// divides a by b modulo MOD (which must be prime), i.e. returns (a * b^{-1} mod MOD).
int div_mod(int a, int b) {
    // assumes MOD is prime, gcd(b,MOD)=1
    return mul_mod(a, inv_mod(b));
}
```

---

## 18. Additional Tips & Tricks

1. **Always Reduce After Every Operation.**

   Example: when adding two large products, do

   ```cpp
   long long x = mul_mod(A, B);
   long long y = mul_mod(C, D);
   int ans = add_mod(int(x), int(y));
   ```

   rather than mixing 64-bit and 32-bit in one line.
2. **Use 64-bit (`long long`) Early If MOD≈10^9.**

   Because 109×109=101810^9 \times 10^9 = 10^{18} still fits in signed 64-bit, but not in 32-bit.
3. **When Doing Repeated Multiplication (e.g.\ Factorials  mod  p\bmod\,p), Precompute Once.**

   ```cpp
   const int NMAX = 1'000'000;
   vector<long long> fact(NMAX+1), invfact(NMAX+1);

   void build_factorials() {
       fact[0] = 1;
       for (int i = 1; i <= NMAX; i++) {
           fact[i] = (fact[i-1] * i) % MOD;
       }
       // invfact[NMAX] = (fact[NMAX])^(MOD-2) mod MOD
       invfact[NMAX] = mod_pow(fact[NMAX], MOD - 2);
       for (int i = NMAX; i > 0; i--) {
           invfact[i-1] = (invfact[i] * i) % MOD;
       }
   }

   // nCk % MOD
   long long nCr(int n, int k) {
       if (k < 0 || k > n) return 0;
       return ((fact[n] * invfact[k]) % MOD) * invfact[n-k] % MOD;
   }
   ```
4. **Practice Binary Exponentiation Separately.**

   Get so comfortable that when you see “compute ab mod ma^b \bmod m,” your fingers type it without thinking (and in under 20 seconds).
5. **CRT Templates.**

   If you plan to solve many CRT problems, have a little helper function:

   ```cpp
   // solve x ≡ a1 (mod n1), x ≡ a2 (mod n2), assuming gcd(n1,n2)=1
   // returns pair (x mod n1*n2, n1*n2).
   pair<long long,long long> crt2(long long a1, long long n1, 
                                  long long a2, long long n2) {
       // Compute p, q so that n1*p + n2*q = 1 (ext_gcd)
       long long p, q;
       long long g = ext_gcd(n1, n2, p, q);
       // (We assume g=1 because they’re coprime.)
       long long mod = n1 * n2;
       // Now a1 + n1*k ≡ a2 (mod n2) 
       // => n1*k ≡ (a2 - a1) (mod n2) 
       // => k ≡ (a2 - a1) * (n1^{-1} mod n2) (mod n2).
       long long inv_n1_mod_n2 = inv_mod_ll(n1 % n2, n2);
       long long k = ((a2 - a1) % n2 + n2) % n2;
       k = (k * inv_n1_mod_n2) % n2;
       long long x = (a1 + n1 * k) % mod;
       if (x < 0) x += mod;
       return {x, mod};
   }
   ```

   Then if you have more than two moduli, chain them:

   (x12, m12)=crt2(a1, m1,  a2, m2),(x123, m123)=crt2(x12, m12,  a3, m3),  …  (x_{12},\,m_{12}) = \mathrm{crt2}(a_1,\,m_1,\;a_2,\,m_2),
   \quad
   (x_{123},\,m_{123}) = \mathrm{crt2}(x_{12},\,m_{12},\;a_3,\,m_3),\;\dots

---

## 19. Codeforces Practice Plan (Week by Week)

Below is a suggested 12-week plan to solidify your modular and number-theory skills.  Each week, set aside 10–15 hours to solve problems and read editorials.

| Week | Focus                                                                                                     | Rough Target                                                                                                                           |
| :--: | :-------------------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------- |
|  1  | **Implement your Modular Template.** – Add/sub/mul, pow, inv (prime), ext_gcd.                     | Verify with small “hand‐made” problems.  Solve 5 toy “compute (a+b)%m” problems on CF.                                            |
|  2  | **Basic Modular Problems (rats on CF).** 800–1000 rated with tag “math” or “modular.”          | Solve at least**15**such problems—examples: 1485A (Add and Divide), 1629A (Download More RAM), 1101A (Minimum Integer).         |
|  3  | **Fermat’s Little Theorem & Fast Exponentiation**Implementation and micro-benchmarks.              | Write your own `modPow(a, b)`.  Solve 5 problems where you need to compute very large exponents mod prime.                           |
|  4  | **Extended GCD & Inverses (Composite)** .**  Run extended gcd on ~1000.**                           | Solve 5 CF problems that require computing inverse mod a*composite* nn.  E.g. “Find x such thata x≡b(modn)a\,x \equiv b\pmod{n}.” |
|  5  | **Euler’sφ\varphiFunction & Totient Arithmetic.** Implement sieve forφ(n)\varphi(n)up to10610^6. | Solve 3 problems tagged “totient” or “φ(n).”  E.g. “Givennn, compute sum of gcd(n,i)(n,i)for allii.”                            |
|  6  | **Chinese Remainder Theorem (CRT).**Learn the 2-modulus recipe; chain to 3+.                              | Solve 3 CRT problems:                                                                                                                  |

1. “Find xx s.t.x mod 4=a,  x mod 7=bx \bmod 4 = a,\;x \bmod 7 = b.”
2. “Find smallest non-neg xx for 3 simultaneous congruences.”
3. A random CF problem tagged “CRT.”                                                                         |

   |  7  | **Combinatorics Mod 109+710^9+7.** Precompute factorials and inverses; compute (nk)\binom{n}{k}. | Solve 5 problems that require “print answer mod 109+710^9+7” for combinations (e.g. “# of subsets of size kk with some property”).                                        |

   |  8  | **Binary Exponentiation Variants.** Practice with matrix exponentiation mod 109+710^9+7.         | Solve 2 problems requiring “fast power of a 2×2 matrix mod.”  (Often labeled “fibonacci in O(log n)”).                                                                     |

   |  9  | **Hybrid Problems (mod + DP + greedy).** Look at 1200–1400 rated “math+dp” problems.           | Solve 5 problems where you need to do DP but states are “remainder mod kk.”  For instance, “given an array, count subsequences whose sum is divisible by 33.”        |

   | 10  | **Speed Practice: Timed 1-hour Session.** Pick a random Div 3 Round; solve 3 math/nt problems.     | Aim to complete them in < 60 minutes total, with full editorial reading afterward.                                                                                            |

   | 11  | **Make Your Own Mini‐Library** (“snippet.h”) — with modular arithmetic, ext_gcd, CRT.            | Write a single `.h` file that you can `#include` in every contest.  Test it on 3 new CF problems; don’t retype anything by hand.                                               |

   | 12  |  **Contest Simulation + Review.** Join a live Div 3/Div 2 contest, solve as many as you can.  | After the contest, spend 2 hours reading all editorials for the problems you didn’t solve.  Fix your template if you needed any new function (e.g.\ “mod combination rev”). |

By the end of these 12 weeks, you will:

1. Have a rock-solid modular arithmetic template.
2. Have solved dozens of problems involving inverses, CRT, fast exponentiation, and totient.
3. Be comfortable reading and writing small snippets (e.g.\ computing x−1(modn)x^{-1}\pmod{n} in under 30 seconds).
4. Have a clear path from 800-rated contests up into the 1300–1400 zone.

Continue in a like fashion—over the next 12 months—increasing difficulty of problems (“1500–1800 rated,” “combinatorics + nt,” “FFT,” “number theory with geometry,” etc.).  By “putting in the reps,” polishing your template, and participating in contests regularly, you will *guarantee* that by the end of 2025 you are Codeforces Expert (≥ 1900 rating).

---

## 20. Quick Recap Checklist Before You Close This Tab

* [ ] Can you reduce any sum/difference/product mod nn in one line of code?
* [ ] Do you know how to compute `modPow(base, exp, mod)` in O(log⁡exp)O(\log\text{exp})?
* [ ] Do you know how to find `inv(a, mod)` when `mod` is prime (via FLT) and when `mod` is composite (via `ext_gcd`)?
* [ ] Can you solve a two‐equation CRT instance in < 2 minutes on paper?
* [ ] Do you have a C++ snippet you can paste at the top of any contest solution?
* [ ] Have you solved at least ten 800–1000 rated CF problems with “math/number theory” tags?

If you answered “yes” to all of the above, you’re set to keep climbing.  Each time you see a “mod” or “inverse” or “CRT” keyword, you will know exactly which snippet to pull from your toolkit.

Good luck on your journey to Codeforces Expert—practice consistently, read editorials *every time* you get stuck, and never be afraid to revisit the basics.  By the end of 2025, you’ll not only *understand* modular arithmetic and CRT in your sleep, but you’ll also solve “hard” problems that require combining them with DP, combinatorics, and more advanced number theory.

Happy coding!
