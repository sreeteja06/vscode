spell_check = {'get':1, 'home':1}
'''user_input=input("enter a string:")
if spell_check.get(user_input) is None:
    print("spelling mistake:1;")
spell_check[user_input]=1
if spell_check.get(user_input) is None:
    print("spelling mistake:2;")
else:
    print("correct word;")
print(spell_check)'''
for i in range(3):
    item,hell = input().strip().strip
    spell_check[item] = hell
    print(spell_check[item])