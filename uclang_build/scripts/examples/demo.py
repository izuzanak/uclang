
class Person:
    def __init__(self,a_name,a_surname):
        self.name = a_name;
        self.surname = a_surname;

persons = {
  "omar" : Person('Omar','Little'),
  "avone" : Person('Avone','Barksdale')
}

def person_dict():
    result = {}

    for id in persons:
        result[id] = persons[id].__dict__;

    return result

def person_list():
    result = []

    for id in persons:
        person = persons[id]
        result.append(person.name + ' ' + person.surname)

    return result

def json(a_json,a_dict):
    return a_json.dumps(a_dict,separators=(',',':'))

