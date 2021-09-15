from Vehicle.VehicleBase import VehicleBase

class ModelY(VehicleBase):
    def __init__(self, name, speed, range, hp, desc, price):
        super().__init__(name, speed, range, hp)
        self.description = desc
        self.price = price
        self.type = "Standard"

    def get_details(self) -> str:
        desp = super().get_details()
        desp += str('\r\n\tprice: ${} \r\n\ttype = {} \r\n\tdescription = {}\r\n'.format(self.price, self.type, self.description))
        return desp