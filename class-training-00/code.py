class person:
	def __init__(self,name,age):
		self.name = name
		self.age = age
	def myfunc(self):
		print(self.name + " is " + str(self.age) + " years old")
	def __call__(self, name, age):
		self.name = name
		self.age = age

p = person("Ophen",19)
p.myfunc()

p.age = 20
p.myfunc()

p2 = person("Saad",22)
print(f"the combined age of {p.name} and {p2.name} is {p.age + p2.age}")

if p.age > p2.age:
	print(f"{p.name} is older than {p2.name}")
else:
	print(f"{p2.name} is older than {p.name}")

persons = []
persons.append(person("Jawad",99))
persons[0].myfunc();

persons.append(person("rida",55))
persons[1].myfunc();

persons.append(p)
persons[2].myfunc();

del persons[1]
persons[1].myfunc();

persons[0]("Rina", 18);
persons[0].myfunc();