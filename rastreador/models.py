from django.db import models

# Create your models here.

class Data(models.Model):

    Latitude = models.FloatField(max_length=8)
    Longitude = models.FloatField(max_length=8)
    # Altitude = models.FloatField(max_length=6)
    # HorarioESP = models.FloatField(max_length=8)
    # VelocidadeKM = models.FloatField(max_length=6)
    # Satelites = models.IntegerField()