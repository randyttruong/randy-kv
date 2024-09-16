import { NestFactory } from '@nestjs/core';
import { NodeDiscoveryModule } from './node_discovery.module';
import { Transport, MicroserviceOptions } from "@nestjs/microservices";
import { join } from 'path';
import { ReflectionService } from "@grpc/reflection";

async function bootstrap() {

  const app = await NestFactory.createMicroservice<MicroserviceOptions>(NodeDiscoveryModule, {
    transport: Transport.GRPC,
    options: {
      onLoadPackageDefinition: (pkg, server) => {
        new ReflectionService(pkg).addToServer(server);
      },
      package: ['discovery'],
      protoPath: [
          join(__dirname, '../../proto/discovery.proto'),
          join(__dirname, '../../proto/google/protobuf/empty.proto')
      ],
      url: '0.0.0.0:50051',
    }
  })

  await app.listen();
}
bootstrap();
