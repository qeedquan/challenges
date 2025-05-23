/*

We want to create a constructor function 'NameMe', which takes first name and last name as parameters. The function combines the first and last names and saves the value in "name" property.

We already implemented that function, but when we actually run the code, the "name" property is accessible, but the "firstName" and "lastName" is not accessible. All the properties should be accessible. Can you find what's wrong with it?
A test fixture is also available

public class NameMe {
    private String firstName;
    private String lastName;
    private String fullName;

    public NameMe(String first, String last) {
        this.firstName = first;
        this.lastName = last;
   }
 }

NameMe nameMe = new NameMe("John", "Doe");
nameMe.getFirstName(); //Expected: John
nameMe.getLastName(); //Expected: Doe
nameMe.getFullName(); //Expected: John Doe

*/

struct Name {
    first: String,
    last: String,
    full: String,
}

impl Name {
    fn new(first: &'static str, last: &'static str) -> Self {
        Name {
            first: format!("{first}"),
            last: format!("{last}"),
            full: format!("{first} {last}"),
        }
    }
}

fn main() {
    let name = Name::new("John", "Doe");
    assert_eq!(name.first, "John");
    assert_eq!(name.last, "Doe");
    assert_eq!(name.full, "John Doe");
}
