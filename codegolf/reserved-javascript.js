/*

As of ECMAScript 2015, JavaScript has 33 reserved keywords, such as break, const and new, as well as 10 future reserved keywords, such as let and await.

Your task is to chain together the largest number of consecutive1 distinct reserved keywords2 while writing functional JavaScript code3.

Consecutive reserved keywords - reserved keywords that are separated only by whitespace and/or parentheses and/or curly braces.
Reserved keywords - any reserved or future reserved keywords as of ECMAScript 2015. Reserved keywords from older standards are excluded, a full list of allowed keywords is given below.
Functional code - your code should run (state your runtime, if necessary), eventually halt, and not throw any runtime errors.
If your code needs a specific runtime, the used reserved keywords must not be no-ops in the given environment.

List of reserved keywords
Show code snippet

Scoring & examples
Your score will be equal to the largest number of consecutive distinct reserved keywords.
In the case of equal scores, shortest source code in bytes wins. Commented sections and strings don't count towards reserved keywords, but count towards byte count.

// score: 3
if (true) 0; else throw function() {}
             ^------------------^
// score: 2
let foo = typeof typeof void typeof void 0;
                             ^---------^
// score: 0
/* typeof default debugger * /

// score: 0, doesn't halt or debugger is no-op, depending on the environment
debugger;
Standard loopholes apply.

*/

new (class await {
    break(){}
    case(){}
    catch(){}
    const(){}
    continue(){}
    debugger(){}
    default(){}
    delete(){}
    do(){}
    else(){}
    enum(){}
    export(){}
    extends(){}
    finally(){}
    for(){}
    function(){}
    if(){}
    implements(){}
    import(){}
    in(){}
    instanceof(){}
    interface(){}
    let(){}
    package(){}
    private(){}
    protected(){}
    public(){}
    return(){}
    static(){}
    super(){}
    switch(){}
    this(){}
    throw(){}
    try(){}
    typeof(){}
    var(){}
    void(){}
    while(){}
    with(){}
    yield(){}
})
