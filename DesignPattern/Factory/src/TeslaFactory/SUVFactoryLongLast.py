from Vehicle.ModelX import ModelX
from Vehicle.ModelY import ModelY
from TeslaFactory.SUVFactoryBase import SUVFactoryBase

class SUVFactoryLongLast(SUVFactoryBase):
    def create_model_x(self) -> ModelX:
        x = ModelX("ModelX", 3.8, 360, 670, "2022", 99990)
        x.type = "LongLast"
        x.description = "Dual Motor All-Wheel Drive"
        return x

    def create_model_y(self) -> ModelY:
        y = ModelY("ModelY", 4.8, 326, 384, "2022", 48190)
        y.type = "Long Range"
        y.description = "Dual Motor All-Wheel Drive"
        return y