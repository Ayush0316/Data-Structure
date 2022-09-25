# Family Doubly linked list
# In this Family linked list all the grandparents will comes first then their children and their grandchildren
# Head will be the Grandparents.
# Then there child will be below them.
# If we have more then one child related to a parent then we that will be arranged accroding to their age.

# Node for the Family linked list. This node contians there name,age and relation. It also contains pointers to next and previous nodes.
class Node:
    def __init__(self,name,age,relation,prev = None,next = None):
        self.prev = prev
        self.next = next
        self.name = name
        self.relation = relation
        self.age = age

# This is the class family doubly linked list.
class FamilyDoublyLinkedList:
    def __init__(self,name,age,relation):
        self.head = Node(name,age,relation)
        self.tail = self.head

    # For inserting the new node/member in the family list.
    def insert(self,name,age,relation):
        current = self.head

        # Changing the head if we have parent of current head or of same relation but have older age.
        if (current.relation != "Grandparent" and relation == "Grandparent")or (current.relation == "Child" and relation == "Parent") or (current.relation == relation and current.age < age):
            present_head = Node(name,age,relation,next = current)
            present_head.next.prev = present_head
            self.head = present_head
            return

        # Looking for the node exactly one behind all the child nodes.
        if (relation == "Child"):
            while ((current.next is not None) and (current.next.relation != relation)):
                current = current.next

        # Looking for the node exactly one behind all the parent nodes.
        if (relation == "Parent"):
            while((current.next is not None) and (current.next.relation == "Grandparent")):
                current = current.next
        
        # Looking for the exact position for the insertion of the new family member.
        while((current.next is not None) and (current.next.relation == relation)):
            if (current.next.age < age):
                break
            current = current.next

        # Inserting new family member/node in the linked list.
        prev_next = current.next
        current.next = Node(name,age,relation,current,current.next)
        if (prev_next is not None):
            prev_next.prev = current.next
        
        if (current.next.next is None):
            self.tail = current.next

        
    # For deleting/removing a node/family member from the linked list.
    def delete(self, name):
        if self.search(name) is not True:
            print("Not in list")
        else:
            current = self.head
            if (current.name == name):
                self.head = current.next
                if self.head is not None:
                    current.next.prev = None
                else:
                    self.tail = None
                return
            while current is not None:
                if current.next.name == name:
                    current.next = current.next.next
                    if current.next is not None:
                        current.next.prev = current
                    else:
                        self.tail = current
                    break
                else:
                    current = current.next

    # Searching whether wanted family member are present or not. We can look a family member by its age too.
    def search(self,value):
        current = self.head
        
        while current.next is not None:
            if (current.name == value) or (str(current.age) == value):
                return True
        
            current = current.next
        if (current.name == value or str(current.age) == value):
            return True
        return False 

    # Displaying our linked list. grandparent -> child.
    def display(self):
        current = self.head
        while current is not None:
            if current.name is not None:
                print("Name: "+current.name+"  Age: "+str(current.age)+"  Relation: "+current.relation)
            current = current.next
        print()

    # Displaying our linked list. child -> grandparent.
    def display_reverse(self):
        current = self.tail

        while current is not None:
            print("Name: "+current.name+"  Age: "+str(current.age)+"  Relation: "+current.relation)
            current = current.prev
        print()



def options():
    print("Chooses an option from all the avaliable options by inputting that number.")
    print("1. Add a member to the Family.")
    print("2. Search for a family member in the linked list.")
    print("3. Print the family linked list (Grandparents -> children).")
    print("4. Print the family linked list (Children -> Grandparents).")
    print("5. Remove a member from the Family Linked List.")
    print("6. Exit the family linked list.")
    print()

def relations():
    print()
    print(" Relation:   Grandparent")
    print("\t\t Parent")
    print("\t\t Child")
    print()

def main():
    head = None
    print()
    print()
    print("Hello User, Welcome!")
    print("Here you can create a Family Doubly Linked List.")
    print()
    print("PRESS Enter TO GET STARTED.")
    input()
    print()

    while True:
        options()

        choose = int(input("Which option you want to pick?  "))
        print()

        if (choose == 1):
            name = input("Enter the name of the member:  ")
            age = int(input("Enter the age(in integer) of the member:  "))
            relations()
            while(True):
                relation = input("Enter the relation of the member(eg: Grandparent):  ")
                if(relation not in ["Grandparent", "Parent", "Child"]):
                    print()
                    print("Please enter a valid relationship(Case specific)")
                    continue
                break

            if (head == None):
                head = FamilyDoublyLinkedList(name, age, relation)
            else:
                head.insert(name, age, relation)
            print("New member added to the family.")
            print()

        elif (choose == 2):
            print("You can search a family member by its name as well as age.")
            value = input("Please enter the name/age of the family member(name is case specific): ")
            if head.search(value):
                print("Member present in the family.")
            else:
                print("Member isn't present in the family.")
            print()

        elif (choose == 3):
            head.display()

        elif (choose == 4):
            head.display_reverse()

        elif (choose == 5):
            name = input("Enter the name of the member:  ")
            head.delete(name)
            print("Member deleted from the family linked list.")
            print()
        elif (choose == 6):
            print("Thanks for using Family linked list.")
            print()
            print("Created by: \nName: Ayush Kansal\nBranch: Ece\nSid: 21105049")
            print()
            break
        else:
            print("Please enter a valid choose.")
        
        print("PRESS Enter TO CONTINUE.")
        input()
        print()     
    
main()


# Created by:
# Name: Ayush Kansal
# Branch: Ece
# SID: 21105049
