from src.pyextend import mymodule

print("Running add(1, 2) ->", mymodule.add(1, 2))
print("Running sum([1,2,3,4,5]) ->", mymodule.sum([1, 2, 3, 4, 5]))
print("Running reverse('not-palindrome') ->", mymodule.reverse('not-palindrome'))

p = mymodule.Person("pikachu", 3)
print(p)
print(p.name)
print(p.get_name())
print(p.age)
print(p.address)
