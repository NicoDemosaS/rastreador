# Generated by Django 5.1 on 2024-08-25 23:59

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
        ('rastreador', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='Data',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('Horario', models.TimeField()),
                ('Latitude', models.FloatField()),
                ('Longitude', models.FloatField()),
                ('Altitude', models.FloatField()),
                ('VelocidadeKM', models.FloatField()),
                ('Satelites', models.IntegerField()),
            ],
        ),
    ]
