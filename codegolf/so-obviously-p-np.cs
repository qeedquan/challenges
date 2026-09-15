/*

SAT is the problem of determining whether a boolean expression can be made true. For example, (A) can be made true by setting A=TRUE, but (A && !A) can never be true. This problem is known to be NP-complete. See Boolean Satisfiability.

Your task is to write a program for SAT that executes in polynomial time, but may not solve all cases.

For some examples, the reason it is not really polynomial could be because:

There is an edge case that is not obvious but has a poor runtime
The algorithm actually fails to solve the problem in some unexpected case
Some feature of the programming language you are using actually has a longer runtime than you would reasonably expect it to have
Your code actually does something totally different from what it looks like it's doing
You may use any programming language (or combination of languages) you wish. You do not need to provide a formal proof of your algorithm's complexity, but you should at least provide an explanation.

The primary criteria for judging should be how convincing the code is.

This is a popularity contest, so the highest rated answer in a week wins.

*/

/*

@Eric Lippert

You said polynomial runtime. You said nothing about polynomial compile time.
This program forces the C# compiler to try all possible type combinations for x1, x2 and x3, and choose the unique one that exhibits no type errors.
The compiler does all the work, so the runtime doesn't have to. I first exhibited this interesting techinque on my blog in 2007:
http://blogs.msdn.com/b/ericlippert/archive/2007/03/28/lambda-expressions-vs-anonymous-methods-part-five.aspx
Note that of course this example shows that overload resolution in C# is at least NP-HARD.
Whether it is NP-HARD or actually undecidable depends on certain subtle details in how type convertibility works in the presence of generic contravariance,
but that's a subject for another day.

*/

class SAT {
    class T {}
    class F {}
    
    delegate void DT(T t);
    delegate void DF(F f);
    
    static void M(string name, DT dt)
    {
        System.Console.WriteLine(name + ": true");
        dt(new T());
    }
    
    static void M(string name, DF df)
    {
        System.Console.WriteLine(name + ": false");
        df(new F());
    }
    
    static T Or(T a1, T a2, T a3)
    {
        return new T();
    }
    
    static T Or(T a1, T a2, F a3)
    {
        return new T();
    }
    
    static T Or(T a1, F a2, T a3)
    {
        return new T();
    }
    
    static T Or(T a1, F a2, F a3)
    {
        return new T();
    }
    
    static T Or(F a1, T a2, T a3)
    {
        return new T();
    }
    
    static T Or(F a1, T a2, F a3)
    {
        return new T();
    }
    
    static T Or(F a1, F a2, T a3)
    {
        return new T();
    }
    
    static F Or(F a1, F a2, F a3)
    {
        return new F();
    }
    
    static T And(T a1, T a2)
    {
        return new T();
    }
    
    static F And(T a1, F a2)
    {
        return new F();
    }
    
    static F And(F a1, T a2)
    {
        return new F();
    }
    
    static F And(F a1, F a2)
    {
        return new F();
    }
    
    static F Not(T a)
    {
        return new F();
    }
    
    static T Not(F a)
    {
        return new T();
    }
    
    static void MustBeT(T t) {}

    static void Main()
    {
        M("x1", x1 => M("x2", x2 => M("x3", x3 => MustBeT(
                            And(
                                Not(x3),
                                And(
                                    Not(x1),
                                    And(
                                        Or(x1, x2, x1),
                                        Or(x2, x3, x2)
                                        )
                                    )
                                )
                            )
                        )
                    )
                );
    }
}
